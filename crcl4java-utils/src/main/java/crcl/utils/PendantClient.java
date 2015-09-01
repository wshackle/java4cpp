/* 
 * This is public domain software, however it is preferred
 * that the following disclaimers be attached.
 * 
 * Software Copywrite/Warranty Disclaimer
 * 
 * This software was developed at the National Institute of Standards and
 * Technology by employees of the Federal Government in the course of their
 * official duties. Pursuant to title 17 Section 105 of the United States
 * Code this software is not subject to copyright protection and is in the
 * public domain. This software is experimental.
 * NIST assumes no responsibility whatsoever for its use by other
 * parties, and makes no guarantees, expressed or implied, about its
 * quality, reliability, or any other characteristic. We would appreciate
 * acknowledgment if the software is used. This software can be
 * redistributed and/or modified freely provided that any derivative works
 * bear some notice that they are derived from it, and any modified
 * versions bear some notice that they have been modified.
 * 
 */
package crcl.utils;

import crcl.base.ActuateJointType;
import crcl.base.ActuateJointsType;
import crcl.base.CRCLCommandInstanceType;
import crcl.base.CRCLCommandType;
import crcl.base.CRCLProgramType;
import crcl.base.CRCLStatusType;
import crcl.base.CommandStateEnumType;
import crcl.base.CommandStatusType;
import crcl.base.EndCanonType;
import crcl.base.InitCanonType;
import crcl.base.JointSpeedAccelType;
import crcl.base.JointStatusType;
import crcl.base.JointStatusesType;
import crcl.base.MiddleCommandType;
import crcl.base.MoveToType;
import crcl.base.PointType;
import crcl.base.PoseType;
import crcl.base.PoseType;
import crcl.base.VectorType;
import static crcl.utils.ObjTableJPanel.getAssignableClasses;
import diagapplet.plotter.PlotData;
import diagapplet.plotter.plotterJFrame;
import java.awt.Color;
import java.awt.Desktop;
import java.awt.GraphicsConfiguration;
import java.awt.Point;
import java.awt.Rectangle;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigDecimal;
import java.math.BigInteger;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.TreeSet;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.stream.Collectors;
import javax.swing.JFileChooser;
import javax.swing.JFrame;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JTable;
import javax.swing.JViewport;
import javax.swing.filechooser.FileNameExtensionFilter;
import javax.swing.table.DefaultTableModel;
import javax.xml.bind.JAXBException;
import javax.xml.datatype.XMLGregorianCalendar;
import javax.xml.parsers.ParserConfigurationException;
import javax.xml.xpath.XPathExpressionException;
import org.xml.sax.SAXException;
import rcs.posemath.PmException;
import rcs.posemath.PmRotationMatrix;
import rcs.posemath.PmRotationVector;
import rcs.posemath.PmRpy;
import rcs.posemath.Posemath;



/**
 *
 * @author Will Shackleford{@literal <william.shackleford@nist.gov> }
 */
public class PendantClient extends javax.swing.JFrame implements PendantClientOuter {

    public PendantClient(GraphicsConfiguration gc) throws ParserConfigurationException {
        super(gc);
        this.internal = new PendantClientInner(this);
        init();
    }

    public PendantClient(String title) throws ParserConfigurationException {
        super(title);
        this.internal = new PendantClientInner(this);
        init();
        setTitle(title);
    }

    /**
     * Creates new form PendantClient
     * @throws javax.xml.parsers.ParserConfigurationException when javax.xml.parsers.DocumentBuilderFactory fails in XpathUtils
     */
    public PendantClient() throws ParserConfigurationException {
        super();
        this.internal = new PendantClientInner(this);
        init();
    }

    private void init() {
        initComponents();
        addCommandsMenu();

        String portPropertyString = System.getProperty("crcljava.port");
        if(null != portPropertyString) {
            this.jTextFieldPort.setText(portPropertyString);
        }
        String hostPropertyString = System.getProperty("crcljava.host");
        if(null != hostPropertyString) {
            this.jTextFieldHost.setText(hostPropertyString);
        }
        internal.setStatSchema(CRCLSocket.readStatSchemaFiles(PendantClient.statSchemasFile));
        internal.setCmdSchema(CRCLSocket.readCmdSchemaFiles(PendantClient.cmdSchemasFile));
        internal.setProgramSchema(CRCLSocket.readProgramSchemaFiles(PendantClient.programSchemasFile));
        readRecentCommandFiles();
        readRecentPrograms();
        this.jTextFieldJointJogIncrement.setText(Double.toString(internal.getJogIncrement()));
        final String programPropertyString = System.getProperty("crcljava.program");
        if(null != programPropertyString) {
            java.awt.EventQueue.invokeLater(new Runnable() {

                @Override
                public void run() {
                    try {
                        openXmlProgramFile(new File(programPropertyString));
                    } catch (ParserConfigurationException | JAXBException | XPathExpressionException | IOException | SAXException ex) {
                        showMessage(ex);
                        LOGGER.log(Level.SEVERE, null, ex);
                    }
                }
            });
        }
    }

    private void readRecentCommandFiles() {
        File fMainDir = new File(System.getProperty("user.home"), recent_files_dir);
        if (!fMainDir.exists()) {
            return;
        }
        File fa[] = fMainDir.listFiles(new java.io.FileFilter() {

            @Override
            public boolean accept(File pathname) {
                return pathname.isDirectory() && pathname.canRead();
            }
        });
        if (null == fa || fa.length < 1) {
            return;
        }
        Arrays.sort(fa, new Comparator<File>() {

            @Override
            public int compare(File o1, File o2) {
                return o1.getName().compareTo(o2.getName());
            }
        });
        for (File fSubDir : fa) {
            JMenu jm = new JMenu(fSubDir.getName());
            this.jMenuCommandRecent.add(jm);
            File sub_fa[] = fSubDir.listFiles(new java.io.FilenameFilter() {

                @Override
                public boolean accept(File dir, String name) {
                    return name.endsWith(".xml");
                }
            });
            Arrays.sort(sub_fa, new Comparator<File>() {

                @Override
                public int compare(File o1, File o2) {
                    return Long.compare(o1.lastModified(), o2.lastModified());
                }
            });
            for (int i = 0; i < sub_fa.length && i < 3; i++) {
                File xmlFile = sub_fa[i];
                JMenuItem jmi = new JMenuItem(xmlFile.getName());
                jmi.addActionListener(new ActionListener() {

                    @Override
                    public void actionPerformed(ActionEvent e) {
                        try {
                            openXmlInstanceFile(xmlFile);
                        } catch (ParserConfigurationException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        } catch (JAXBException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                            showMessage(ex);
                        } catch (XPathExpressionException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                            showMessage(ex);
                        } catch (IOException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                            showMessage(ex);
                        } catch (SAXException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                            showMessage(ex);
                        }
                    }
                });
                jm.add(jmi);
            }
        }

    }
    public static final Logger LOGGER = Logger.getLogger(PendantClient.class.getName());

    public void openXmlProgramFile(File f) throws ParserConfigurationException, JAXBException, XPathExpressionException, IOException, SAXException {
        internal.openXmlProgramFile(f);
    }

    public void saveXmlProgramFile(File f) throws ParserConfigurationException, JAXBException, XPathExpressionException, IOException, SAXException {
        internal.saveXmlProgramFile(f);
    }

    @Override
    public boolean isRecordPoseSelected() {
        return this.jCheckBoxMenuItemRecordPoseList.isSelected();
    }
    
    
    @Override
    public void finishOpenXmlProgramFile(File f, CRCLProgramType program) {
        try {
            showProgram(program);
            internal.setProgram(program);
            this.saveRecentProgram(f);
            this.jTabbedPane1.setSelectedComponent(this.jPanelProgram);
        } catch (JAXBException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
            showMessage(ex);
        } catch (IOException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    private String getFirstLine(File f) throws IOException {
        try (BufferedReader br = new BufferedReader(new FileReader(f))) {
            return br.readLine();
        }
    }

    private Set<String> getRecentPrograms() {
        File fMainDir = new File(System.getProperty("user.home"), recent_programs_dir);
        Set<String> pathSet = new TreeSet<String>();
        if (!fMainDir.exists()) {
            return pathSet;
        }
        File fa[] = fMainDir.listFiles(new java.io.FileFilter() {

            @Override
            public boolean accept(File pathname) {
                return !pathname.isDirectory() && pathname.canRead();
            }
        });
        if (null == fa || fa.length < 1) {
            return pathSet;
        }
        Arrays.sort(fa, new Comparator<File>() {

            @Override
            public int compare(File o1, File o2) {
                return o1.getName().compareTo(o2.getName());
            }
        });
        this.jMenuRecentProgram.removeAll();
        for (File f : fa) {
            try {
                String path = getFirstLine(f).trim();
                File fprog = new File(path);
                if (!fprog.exists() || !fprog.canRead() || fprog.isDirectory()) {
                    f.delete();
                    continue;
                }
                final String fprogCanon = fprog.getCanonicalPath();
                if (pathSet.contains(fprogCanon)) {
                    continue;
                }
                pathSet.add(fprogCanon);
            } catch (IOException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
        }
        return pathSet;
    }

    private void readRecentPrograms() {
        Set<String> pathSet = this.getRecentPrograms();
        for (final String fprogCanon : pathSet) {
            try {
                JMenuItem jmi = new JMenuItem(fprogCanon);
                jmi.addActionListener(new ActionListener() {

                    @Override
                    public void actionPerformed(ActionEvent e) {
                        try {
                            openXmlProgramFile(new File(fprogCanon));
                        } catch (ParserConfigurationException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        } catch (JAXBException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        } catch (XPathExpressionException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        } catch (IOException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        } catch (SAXException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        }
                    }
                });
                this.jMenuRecentProgram.add(jmi);
            } catch (Exception ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
        }
    }

    private void addCommandsMenu() {
        try {
            List<Class> allClasses = ObjTableJPanel.getClasses();
            List<Class> cmdClasses = ObjTableJPanel.getAssignableClasses(CRCLCommandType.class,
                    allClasses);
            Collections.sort(cmdClasses, new Comparator<Class>() {
                
                @Override
                public int compare(Class o1, Class o2) {
                    return o1.getCanonicalName().compareTo(o2.getCanonicalName());
                }
            });
            for (final Class c : cmdClasses) {
                JMenuItem jmi = new JMenuItem(c.getCanonicalName());
                jmi.addActionListener(new ActionListener() {
                    
                    @Override
                    public void actionPerformed(ActionEvent e) {
                        try {
                            CRCLCommandType cmd = (CRCLCommandType) c.newInstance();
                            cmd
                                    = (CRCLCommandType) ObjTableJPanel.editObject(cmd,
                                            internal.getXpu(), PendantClient.this.internal.getCheckCommandValidPredicate());
                            internal.incAndSendCommand(cmd);
                            saveRecentCommand(cmd);
                        } catch (InstantiationException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        } catch (IllegalAccessException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        } catch (JAXBException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        } catch (IOException ex) {
                            LOGGER.log(Level.SEVERE, null, ex);
                        }
                    }
                });
                this.jMenuCmds.add(jmi);
            }
        } catch (Throwable e) {
            LOGGER.log(Level.SEVERE, null, e);
        }
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel1 = new javax.swing.JPanel();
        jLabel3 = new javax.swing.JLabel();
        jTextFieldStatCmdID = new javax.swing.JTextField();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTableJoints = new javax.swing.JTable();
        jLabel6 = new javax.swing.JLabel();
        jTextFieldStatus = new javax.swing.JTextField();
        jScrollPane3 = new javax.swing.JScrollPane();
        jTablePose = new javax.swing.JTable();
        jTextFieldStatusID = new javax.swing.JTextField();
        jLabel10 = new javax.swing.JLabel();
        jPanel3 = new javax.swing.JPanel();
        jScrollPane1 = new javax.swing.JScrollPane();
        jTextAreaErrors = new javax.swing.JTextArea();
        jPanel5 = new javax.swing.JPanel();
        jTextFieldPort = new javax.swing.JTextField();
        jButtonConnect = new javax.swing.JButton();
        jButtonDisconnect = new javax.swing.JButton();
        jButtonEnd = new javax.swing.JButton();
        jButtonInit = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jTextFieldHost = new javax.swing.JTextField();
        jLabel2 = new javax.swing.JLabel();
        jCheckBoxPoll = new javax.swing.JCheckBox();
        jTextFieldPollTime = new javax.swing.JTextField();
        jLabel4 = new javax.swing.JLabel();
        jPanel6 = new javax.swing.JPanel();
        jTabbedPane1 = new javax.swing.JTabbedPane();
        jPanelJogging = new javax.swing.JPanel();
        jComboBox1 = new javax.swing.JComboBox();
        jPanelJogMinus = new javax.swing.JPanel();
        jLabelJogMinus = new javax.swing.JLabel();
        jPanelJogPlus = new javax.swing.JPanel();
        jLabelJogPlus = new javax.swing.JLabel();
        jComboBoxXYZRPY = new javax.swing.JComboBox();
        jPanelJogPlus1 = new javax.swing.JPanel();
        jLabelJogPlus1 = new javax.swing.JLabel();
        jPanelJogMinus1 = new javax.swing.JPanel();
        jLabelJogMinus1 = new javax.swing.JLabel();
        jLabel5 = new javax.swing.JLabel();
        jLabel7 = new javax.swing.JLabel();
        jLabel8 = new javax.swing.JLabel();
        jTextFieldJointJogIncrement = new javax.swing.JTextField();
        jTextFieldXYZJogIncrement = new javax.swing.JTextField();
        jTextFieldRPYJogIncrement = new javax.swing.JTextField();
        jLabel9 = new javax.swing.JLabel();
        jTextFieldJogTime = new javax.swing.JTextField();
        jPanelMoveTo = new javax.swing.JPanel();
        jButtonMoveTo = new javax.swing.JButton();
        jScrollPane4 = new javax.swing.JScrollPane();
        jTableMoveToPose = new javax.swing.JTable();
        jCheckBoxStraight = new javax.swing.JCheckBox();
        jButtonMoveToCurrent = new javax.swing.JButton();
        jPanelProgram = new javax.swing.JPanel();
        jScrollPaneProgram = new javax.swing.JScrollPane();
        jTableProgram = new javax.swing.JTable();
        jButtonProgramPause = new javax.swing.JButton();
        jButtonProgramAbort = new javax.swing.JButton();
        jButtonEditProgramItem = new javax.swing.JButton();
        jButtonDeletProgramItem = new javax.swing.JButton();
        jButtonAddProgramItem = new javax.swing.JButton();
        jButtonProgramRun = new javax.swing.JButton();
        jButtonResume = new javax.swing.JButton();
        jButtonPlotProgramItem = new javax.swing.JButton();
        jMenuBarReplaceCommandState = new javax.swing.JMenuBar();
        jMenu1 = new javax.swing.JMenu();
        jMenuItemOpenXmlCommandInstance = new javax.swing.JMenuItem();
        jMenuCommandRecent = new javax.swing.JMenu();
        jMenuItemOpenXmlProgram = new javax.swing.JMenuItem();
        jMenuRecentProgram = new javax.swing.JMenu();
        jMenuItemSaveProgramAs = new javax.swing.JMenuItem();
        jMenuItemSavePoseList = new javax.swing.JMenuItem();
        jMenuItemExit = new javax.swing.JMenuItem();
        jMenu2 = new javax.swing.JMenu();
        jMenuTools = new javax.swing.JMenu();
        jMenuItemXPathQuery = new javax.swing.JMenuItem();
        jCheckBoxMenuItemPlotXYZ = new javax.swing.JCheckBoxMenuItem();
        jCheckBoxMenuItemJoints = new javax.swing.JCheckBoxMenuItem();
        jMenuItemRunTest = new javax.swing.JMenuItem();
        jCheckBoxMenuItemRecordPoseList = new javax.swing.JCheckBoxMenuItem();
        jMenuItemPoseList3DPlot = new javax.swing.JMenuItem();
        jMenuItemOpenStatusLog = new javax.swing.JMenuItem();
        jMenuCmds = new javax.swing.JMenu();
        jMenuXmlSchemas = new javax.swing.JMenu();
        jMenuItemSetSchemaFiles = new javax.swing.JMenuItem();
        jCheckBoxMenuItemValidateXml = new javax.swing.JCheckBoxMenuItem();
        jMenuOptions = new javax.swing.JMenu();
        jCheckBoxMenuItemReplaceState = new javax.swing.JCheckBoxMenuItem();
        jCheckBoxMenuItemDebugWaitForDone = new javax.swing.JCheckBoxMenuItem();
        jCheckBoxMenuItemDebugSendCommand = new javax.swing.JCheckBoxMenuItem();
        jCheckBoxMenuItemDebugReadStatus = new javax.swing.JCheckBoxMenuItem();
        jCheckBoxMenuItemUseEXI = new javax.swing.JCheckBoxMenuItem();
        jCheckBoxMenuItemUseReadStatusThread = new javax.swing.JCheckBoxMenuItem();

        FormListener formListener = new FormListener();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setTitle("CRCL Pendant Client");

        jPanel1.setBorder(javax.swing.BorderFactory.createTitledBorder("Status"));

        jLabel3.setText("Command ID:");

        jTextFieldStatCmdID.setEditable(false);
        jTextFieldStatCmdID.setText("0");

        jTableJoints.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                { new Integer(1), null, null, null},
                { new Integer(2), null, null, null},
                { new Integer(3), null, null, null},
                { new Integer(4), null, null, null},
                { new Integer(5), null, null, null},
                { new Integer(6), null, null, null}
            },
            new String [] {
                "Joint", "Position", "Velocity", "TorqueOrForce"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.Integer.class, java.lang.Double.class, java.lang.Double.class, java.lang.Double.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane2.setViewportView(jTableJoints);

        jLabel6.setText("Status : ");

        jTablePose.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {"X", null},
                {"Y", null},
                {"Z", null},
                {"XI", null},
                {"XJ", null},
                {"XK", null},
                {"ZI", null},
                {"ZJ", null},
                {"Zk", null},
                {"Roll", null},
                {"Pitch", null},
                {"Yaw", null}
            },
            new String [] {
                "Pose Axis", "Position"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.Double.class
            };
            boolean[] canEdit = new boolean [] {
                false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane3.setViewportView(jTablePose);

        jTextFieldStatusID.setText("0");

        jLabel10.setText("Status ID:");

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                    .addGroup(jPanel1Layout.createSequentialGroup()
                        .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 276, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addGroup(jPanel1Layout.createSequentialGroup()
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                                    .addComponent(jLabel3)
                                    .addComponent(jLabel6)
                                    .addComponent(jLabel10))
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                                    .addComponent(jTextFieldStatCmdID, javax.swing.GroupLayout.DEFAULT_SIZE, 165, Short.MAX_VALUE)
                                    .addComponent(jTextFieldStatus)
                                    .addComponent(jTextFieldStatusID))))
                        .addGap(0, 9, Short.MAX_VALUE))))
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel1Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel3)
                    .addComponent(jTextFieldStatCmdID, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel6)
                    .addComponent(jTextFieldStatus, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextFieldStatusID, javax.swing.GroupLayout.PREFERRED_SIZE, 27, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel10))
                .addGap(18, 18, Short.MAX_VALUE)
                .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 134, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane3, javax.swing.GroupLayout.PREFERRED_SIZE, 261, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );

        jPanel3.setBorder(javax.swing.BorderFactory.createTitledBorder("Errors"));

        jTextAreaErrors.setColumns(20);
        jTextAreaErrors.setLineWrap(true);
        jTextAreaErrors.setRows(5);
        jScrollPane1.setViewportView(jTextAreaErrors);

        javax.swing.GroupLayout jPanel3Layout = new javax.swing.GroupLayout(jPanel3);
        jPanel3.setLayout(jPanel3Layout);
        jPanel3Layout.setHorizontalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jScrollPane1)
        );
        jPanel3Layout.setVerticalGroup(
            jPanel3Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jScrollPane1, javax.swing.GroupLayout.DEFAULT_SIZE, 121, Short.MAX_VALUE)
        );

        jPanel5.setBorder(javax.swing.BorderFactory.createTitledBorder(javax.swing.BorderFactory.createTitledBorder("Connection")));

        jTextFieldPort.setText("64444");

        jButtonConnect.setText("Connect");
        jButtonConnect.addActionListener(formListener);

        jButtonDisconnect.setText("Disconnect ");
        jButtonDisconnect.setEnabled(false);
        jButtonDisconnect.addActionListener(formListener);

        jButtonEnd.setText("End");
        jButtonEnd.setEnabled(false);
        jButtonEnd.addActionListener(formListener);

        jButtonInit.setText("Init");
        jButtonInit.setEnabled(false);
        jButtonInit.addActionListener(formListener);

        jLabel1.setText("Host: ");

        jTextFieldHost.setText("localhost");

        jLabel2.setText("Port:");

        jCheckBoxPoll.setSelected(true);
        jCheckBoxPoll.setText("Poll");
        jCheckBoxPoll.addActionListener(formListener);

        jTextFieldPollTime.setText("200");
        jTextFieldPollTime.addActionListener(formListener);

        jLabel4.setText("Poll interval(ms):");

        javax.swing.GroupLayout jPanel5Layout = new javax.swing.GroupLayout(jPanel5);
        jPanel5.setLayout(jPanel5Layout);
        jPanel5Layout.setHorizontalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addComponent(jButtonInit)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonEnd))
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addComponent(jButtonConnect, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonDisconnect, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jCheckBoxPoll))
                    .addGroup(jPanel5Layout.createSequentialGroup()
                        .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel2)
                            .addComponent(jLabel4)
                            .addComponent(jLabel1))
                        .addGap(18, 18, 18)
                        .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                            .addComponent(jTextFieldHost, javax.swing.GroupLayout.DEFAULT_SIZE, 187, Short.MAX_VALUE)
                            .addComponent(jTextFieldPort)
                            .addComponent(jTextFieldPollTime))))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jPanel5Layout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {jButtonConnect, jButtonDisconnect});

        jPanel5Layout.setVerticalGroup(
            jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel5Layout.createSequentialGroup()
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jTextFieldHost, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel2)
                    .addComponent(jTextFieldPort, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextFieldPollTime, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 40, Short.MAX_VALUE)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButtonConnect)
                    .addComponent(jButtonDisconnect)
                    .addComponent(jCheckBoxPoll))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanel5Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButtonInit)
                    .addComponent(jButtonEnd))
                .addContainerGap())
        );

        jPanel6.setBorder(javax.swing.BorderFactory.createEmptyBorder(1, 1, 1, 1));

        jTabbedPane1.setBorder(new javax.swing.border.SoftBevelBorder(javax.swing.border.BevelBorder.RAISED));
        jTabbedPane1.setName(""); // NOI18N

        jPanelJogging.setBorder(javax.swing.BorderFactory.createEmptyBorder(1, 1, 1, 1));
        jPanelJogging.setName("Jogging"); // NOI18N

        jComboBox1.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "Joint 1", "Joint 2", "Joint 3", "Joint 4", "Joint 5", "Joint 6" }));

        jPanelJogMinus.setBackground(new java.awt.Color(255, 255, 255));
        jPanelJogMinus.setBorder(new javax.swing.border.MatteBorder(null));
        jPanelJogMinus.addMouseListener(formListener);

        jLabelJogMinus.setBackground(new java.awt.Color(255, 255, 255));
        jLabelJogMinus.setFont(new java.awt.Font("Cantarell", 0, 18)); // NOI18N
        jLabelJogMinus.setText("Jog -");
        jLabelJogMinus.addMouseListener(formListener);

        javax.swing.GroupLayout jPanelJogMinusLayout = new javax.swing.GroupLayout(jPanelJogMinus);
        jPanelJogMinus.setLayout(jPanelJogMinusLayout);
        jPanelJogMinusLayout.setHorizontalGroup(
            jPanelJogMinusLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelJogMinusLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabelJogMinus)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanelJogMinusLayout.setVerticalGroup(
            jPanelJogMinusLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelJogMinusLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabelJogMinus, javax.swing.GroupLayout.PREFERRED_SIZE, 18, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jPanelJogPlus.setBackground(new java.awt.Color(255, 255, 255));
        jPanelJogPlus.setBorder(new javax.swing.border.MatteBorder(null));

        jLabelJogPlus.setBackground(new java.awt.Color(255, 255, 255));
        jLabelJogPlus.setFont(new java.awt.Font("Cantarell", 0, 18)); // NOI18N
        jLabelJogPlus.setText("Jog +");
        jLabelJogPlus.addMouseListener(formListener);

        javax.swing.GroupLayout jPanelJogPlusLayout = new javax.swing.GroupLayout(jPanelJogPlus);
        jPanelJogPlus.setLayout(jPanelJogPlusLayout);
        jPanelJogPlusLayout.setHorizontalGroup(
            jPanelJogPlusLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelJogPlusLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabelJogPlus)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanelJogPlusLayout.setVerticalGroup(
            jPanelJogPlusLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelJogPlusLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabelJogPlus, javax.swing.GroupLayout.PREFERRED_SIZE, 18, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jComboBoxXYZRPY.setModel(new javax.swing.DefaultComboBoxModel(new String[] { "X", "Y", "Z", "Roll", "Pitch", "Yaw", " " }));

        jPanelJogPlus1.setBackground(new java.awt.Color(255, 255, 255));
        jPanelJogPlus1.setBorder(new javax.swing.border.MatteBorder(null));

        jLabelJogPlus1.setBackground(new java.awt.Color(255, 255, 255));
        jLabelJogPlus1.setFont(new java.awt.Font("Cantarell", 0, 18)); // NOI18N
        jLabelJogPlus1.setText("Jog +");
        jLabelJogPlus1.addMouseListener(formListener);

        javax.swing.GroupLayout jPanelJogPlus1Layout = new javax.swing.GroupLayout(jPanelJogPlus1);
        jPanelJogPlus1.setLayout(jPanelJogPlus1Layout);
        jPanelJogPlus1Layout.setHorizontalGroup(
            jPanelJogPlus1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelJogPlus1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabelJogPlus1)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanelJogPlus1Layout.setVerticalGroup(
            jPanelJogPlus1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelJogPlus1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabelJogPlus1, javax.swing.GroupLayout.PREFERRED_SIZE, 18, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jPanelJogMinus1.setBackground(new java.awt.Color(255, 255, 255));
        jPanelJogMinus1.setBorder(new javax.swing.border.MatteBorder(null));
        jPanelJogMinus1.addMouseListener(formListener);

        jLabelJogMinus1.setBackground(new java.awt.Color(255, 255, 255));
        jLabelJogMinus1.setFont(new java.awt.Font("Cantarell", 0, 18)); // NOI18N
        jLabelJogMinus1.setText("Jog -");
        jLabelJogMinus1.addMouseListener(formListener);

        javax.swing.GroupLayout jPanelJogMinus1Layout = new javax.swing.GroupLayout(jPanelJogMinus1);
        jPanelJogMinus1.setLayout(jPanelJogMinus1Layout);
        jPanelJogMinus1Layout.setHorizontalGroup(
            jPanelJogMinus1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelJogMinus1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabelJogMinus1)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanelJogMinus1Layout.setVerticalGroup(
            jPanelJogMinus1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelJogMinus1Layout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jLabelJogMinus1, javax.swing.GroupLayout.PREFERRED_SIZE, 18, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jLabel5.setText("Joint Jog Increment: ");

        jLabel7.setText("XYZ Jog Increment:");

        jLabel8.setText("RPY Jog Increment:");

        jTextFieldJointJogIncrement.setText("3.0");
        jTextFieldJointJogIncrement.addActionListener(formListener);

        jTextFieldXYZJogIncrement.setText("3.0");
        jTextFieldXYZJogIncrement.addActionListener(formListener);

        jTextFieldRPYJogIncrement.setText("3.0");
        jTextFieldRPYJogIncrement.addActionListener(formListener);

        jLabel9.setText("Jog Time Period (ms) :");

        jTextFieldJogTime.setText("200");
        jTextFieldJogTime.addActionListener(formListener);

        javax.swing.GroupLayout jPanelJoggingLayout = new javax.swing.GroupLayout(jPanelJogging);
        jPanelJogging.setLayout(jPanelJoggingLayout);
        jPanelJoggingLayout.setHorizontalGroup(
            jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelJoggingLayout.createSequentialGroup()
                .addGroup(jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanelJoggingLayout.createSequentialGroup()
                        .addContainerGap()
                        .addGroup(jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jLabel5)
                            .addComponent(jLabel7)
                            .addComponent(jLabel9)
                            .addComponent(jLabel8))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGroup(jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jTextFieldJogTime, javax.swing.GroupLayout.PREFERRED_SIZE, 131, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jTextFieldRPYJogIncrement, javax.swing.GroupLayout.PREFERRED_SIZE, 131, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jTextFieldXYZJogIncrement, javax.swing.GroupLayout.PREFERRED_SIZE, 105, javax.swing.GroupLayout.PREFERRED_SIZE)
                            .addComponent(jTextFieldJointJogIncrement, javax.swing.GroupLayout.PREFERRED_SIZE, 131, javax.swing.GroupLayout.PREFERRED_SIZE)))
                    .addGroup(jPanelJoggingLayout.createSequentialGroup()
                        .addGap(12, 12, 12)
                        .addGroup(jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addGroup(jPanelJoggingLayout.createSequentialGroup()
                                .addComponent(jComboBoxXYZRPY, javax.swing.GroupLayout.PREFERRED_SIZE, 108, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jPanelJogMinus1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jPanelJogPlus1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                            .addGroup(jPanelJoggingLayout.createSequentialGroup()
                                .addComponent(jComboBox1, javax.swing.GroupLayout.PREFERRED_SIZE, 108, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jPanelJogMinus, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                                .addComponent(jPanelJogPlus, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)))))
                .addGap(0, 0, Short.MAX_VALUE))
        );

        jPanelJoggingLayout.linkSize(javax.swing.SwingConstants.HORIZONTAL, new java.awt.Component[] {jTextFieldJogTime, jTextFieldJointJogIncrement, jTextFieldRPYJogIncrement, jTextFieldXYZJogIncrement});

        jPanelJoggingLayout.setVerticalGroup(
            jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelJoggingLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jPanelJogMinus, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jComboBox1)
                    .addComponent(jPanelJogPlus, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addComponent(jPanelJogMinus1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jComboBoxXYZRPY)
                    .addComponent(jPanelJogPlus1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel5)
                    .addComponent(jTextFieldJointJogIncrement, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(6, 6, 6)
                .addGroup(jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel7)
                    .addComponent(jTextFieldXYZJogIncrement, javax.swing.GroupLayout.PREFERRED_SIZE, 30, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(12, 12, 12)
                .addGroup(jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jTextFieldRPYJogIncrement, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel8, javax.swing.GroupLayout.PREFERRED_SIZE, 18, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanelJoggingLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel9)
                    .addComponent(jTextFieldJogTime, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jTabbedPane1.addTab("Jog", jPanelJogging);

        jPanelMoveTo.setBorder(javax.swing.BorderFactory.createEmptyBorder(1, 1, 1, 1));
        jPanelMoveTo.setName("MoveTo"); // NOI18N

        jButtonMoveTo.setText("MoveTo");
        jButtonMoveTo.addActionListener(formListener);

        jTableMoveToPose.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {"X", null},
                {"Y", null},
                {"Z", null},
                {"XI",  new Double(1.0)},
                {"XJ",  new Double(0.0)},
                {"XK",  new Double(0.0)},
                {"ZI",  new Double(0.0)},
                {"ZJ",  new Double(0.0)},
                {"ZJ",  new Double(1.0)}
            },
            new String [] {
                "Pose Axis", "Position"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.String.class, java.lang.Double.class
            };
            boolean[] canEdit = new boolean [] {
                false, true
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jScrollPane4.setViewportView(jTableMoveToPose);

        jCheckBoxStraight.setText("Straight");

        jButtonMoveToCurrent.setText("Current");
        jButtonMoveToCurrent.addActionListener(formListener);

        javax.swing.GroupLayout jPanelMoveToLayout = new javax.swing.GroupLayout(jPanelMoveTo);
        jPanelMoveTo.setLayout(jPanelMoveToLayout);
        jPanelMoveToLayout.setHorizontalGroup(
            jPanelMoveToLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelMoveToLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanelMoveToLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(jPanelMoveToLayout.createSequentialGroup()
                        .addComponent(jButtonMoveTo)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jCheckBoxStraight)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonMoveToCurrent))
                    .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 286, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        jPanelMoveToLayout.setVerticalGroup(
            jPanelMoveToLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelMoveToLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanelMoveToLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButtonMoveTo)
                    .addComponent(jCheckBoxStraight)
                    .addComponent(jButtonMoveToCurrent))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 191, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );

        jTabbedPane1.addTab("MoveTo", jPanelMoveTo);

        jTableProgram.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                { new Long(1), "InitCanonType",  new Long(-1),  new Double(0.0)},
                { new Long(2), "EndCanonType",  new Long(-1), null}
            },
            new String [] {
                "ID", "Type", "Time To Execute(ms)", "Distance Moved"
            }
        ) {
            Class[] types = new Class [] {
                java.lang.Long.class, java.lang.String.class, java.lang.Long.class, java.lang.Double.class
            };
            boolean[] canEdit = new boolean [] {
                false, false, false, false
            };

            public Class getColumnClass(int columnIndex) {
                return types [columnIndex];
            }

            public boolean isCellEditable(int rowIndex, int columnIndex) {
                return canEdit [columnIndex];
            }
        });
        jTableProgram.setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
        jScrollPaneProgram.setViewportView(jTableProgram);

        jButtonProgramPause.setText("Pause");
        jButtonProgramPause.setEnabled(false);
        jButtonProgramPause.addActionListener(formListener);

        jButtonProgramAbort.setText("Abort");
        jButtonProgramAbort.addActionListener(formListener);

        jButtonEditProgramItem.setText("Edit Item");
        jButtonEditProgramItem.addActionListener(formListener);

        jButtonDeletProgramItem.setText("Delete Item");
        jButtonDeletProgramItem.addActionListener(formListener);

        jButtonAddProgramItem.setText("Add Item");
        jButtonAddProgramItem.addActionListener(formListener);

        jButtonProgramRun.setText("Run From Start");
        jButtonProgramRun.addActionListener(formListener);

        jButtonResume.setText("Resume");
        jButtonResume.setEnabled(false);
        jButtonResume.addActionListener(formListener);

        jButtonPlotProgramItem.setText("Plot");
        jButtonPlotProgramItem.addActionListener(formListener);

        javax.swing.GroupLayout jPanelProgramLayout = new javax.swing.GroupLayout(jPanelProgram);
        jPanelProgram.setLayout(jPanelProgramLayout);
        jPanelProgramLayout.setHorizontalGroup(
            jPanelProgramLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelProgramLayout.createSequentialGroup()
                .addContainerGap()
                .addGroup(jPanelProgramLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPaneProgram, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
                    .addGroup(jPanelProgramLayout.createSequentialGroup()
                        .addComponent(jButtonProgramPause)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonResume)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonProgramAbort)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonProgramRun))
                    .addGroup(jPanelProgramLayout.createSequentialGroup()
                        .addComponent(jButtonEditProgramItem)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonDeletProgramItem)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonAddProgramItem)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jButtonPlotProgramItem)))
                .addContainerGap())
        );
        jPanelProgramLayout.setVerticalGroup(
            jPanelProgramLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanelProgramLayout.createSequentialGroup()
                .addContainerGap()
                .addComponent(jScrollPaneProgram, javax.swing.GroupLayout.DEFAULT_SIZE, 169, Short.MAX_VALUE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanelProgramLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButtonProgramPause)
                    .addComponent(jButtonProgramAbort)
                    .addComponent(jButtonProgramRun)
                    .addComponent(jButtonResume))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(jPanelProgramLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButtonEditProgramItem)
                    .addComponent(jButtonDeletProgramItem)
                    .addComponent(jButtonAddProgramItem)
                    .addComponent(jButtonPlotProgramItem))
                .addContainerGap())
        );

        jTabbedPane1.addTab("Program", jPanelProgram);

        javax.swing.GroupLayout jPanel6Layout = new javax.swing.GroupLayout(jPanel6);
        jPanel6.setLayout(jPanel6Layout);
        jPanel6Layout.setHorizontalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(jPanel6Layout.createSequentialGroup()
                .addComponent(jTabbedPane1)
                .addGap(1, 1, 1))
        );
        jPanel6Layout.setVerticalGroup(
            jPanel6Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jTabbedPane1, javax.swing.GroupLayout.PREFERRED_SIZE, 0, Short.MAX_VALUE)
        );

        jMenu1.setText("File");

        jMenuItemOpenXmlCommandInstance.setText("Open CRCL XML Command Instance File ... ");
        jMenuItemOpenXmlCommandInstance.addActionListener(formListener);
        jMenu1.add(jMenuItemOpenXmlCommandInstance);

        jMenuCommandRecent.setText("Recent CRCL XML Command Instance Files");
        jMenu1.add(jMenuCommandRecent);

        jMenuItemOpenXmlProgram.setText("Open CRCL XML Program File ...");
        jMenuItemOpenXmlProgram.addActionListener(formListener);
        jMenu1.add(jMenuItemOpenXmlProgram);

        jMenuRecentProgram.setText("Recent CRCL XML Program File ...");
        jMenu1.add(jMenuRecentProgram);

        jMenuItemSaveProgramAs.setText("Save Program As ...");
        jMenuItemSaveProgramAs.addActionListener(formListener);
        jMenu1.add(jMenuItemSaveProgramAs);

        jMenuItemSavePoseList.setText("Save Pose List ...");
        jMenuItemSavePoseList.addActionListener(formListener);
        jMenu1.add(jMenuItemSavePoseList);

        jMenuItemExit.setText("Exit");
        jMenuItemExit.addActionListener(formListener);
        jMenu1.add(jMenuItemExit);

        jMenuBarReplaceCommandState.add(jMenu1);

        jMenu2.setText("Edit");
        jMenuBarReplaceCommandState.add(jMenu2);

        jMenuTools.setText(" Tools ");

        jMenuItemXPathQuery.setText("XPath Status  Query ... ");
        jMenuItemXPathQuery.addActionListener(formListener);
        jMenuTools.add(jMenuItemXPathQuery);

        jCheckBoxMenuItemPlotXYZ.setText("2D Plot XYZ vs Time ...");
        jCheckBoxMenuItemPlotXYZ.addActionListener(formListener);
        jMenuTools.add(jCheckBoxMenuItemPlotXYZ);

        jCheckBoxMenuItemJoints.setText("Plot Joints");
        jCheckBoxMenuItemJoints.addActionListener(formListener);
        jMenuTools.add(jCheckBoxMenuItemJoints);

        jMenuItemRunTest.setText("Run Test");
        jMenuItemRunTest.addActionListener(formListener);
        jMenuTools.add(jMenuItemRunTest);

        jCheckBoxMenuItemRecordPoseList.setSelected(true);
        jCheckBoxMenuItemRecordPoseList.setText("Record Pose List");
        jMenuTools.add(jCheckBoxMenuItemRecordPoseList);

        jMenuItemPoseList3DPlot.setText("3D Pose List Plot ...");
        jMenuItemPoseList3DPlot.addActionListener(formListener);
        jMenuTools.add(jMenuItemPoseList3DPlot);

        jMenuItemOpenStatusLog.setText("Open Status Log ...");
        jMenuItemOpenStatusLog.addActionListener(formListener);
        jMenuTools.add(jMenuItemOpenStatusLog);

        jMenuBarReplaceCommandState.add(jMenuTools);

        jMenuCmds.setText("Commands");
        jMenuBarReplaceCommandState.add(jMenuCmds);

        jMenuXmlSchemas.setText("XML Schemas");

        jMenuItemSetSchemaFiles.setText("Set XML Schema Files ... ");
        jMenuItemSetSchemaFiles.addActionListener(formListener);
        jMenuXmlSchemas.add(jMenuItemSetSchemaFiles);

        jCheckBoxMenuItemValidateXml.setSelected(true);
        jCheckBoxMenuItemValidateXml.setText("Validate using Schemas");
        jMenuXmlSchemas.add(jCheckBoxMenuItemValidateXml);

        jMenuBarReplaceCommandState.add(jMenuXmlSchemas);

        jMenuOptions.setText("Options");

        jCheckBoxMenuItemReplaceState.setText("Replace Ready,Done,.. with CRCL_Ready,CRCL_DONE ...");
        jMenuOptions.add(jCheckBoxMenuItemReplaceState);

        jCheckBoxMenuItemDebugWaitForDone.setText("Debug waitForDone()");
        jMenuOptions.add(jCheckBoxMenuItemDebugWaitForDone);

        jCheckBoxMenuItemDebugSendCommand.setText("Debug sendCommand()");
        jMenuOptions.add(jCheckBoxMenuItemDebugSendCommand);

        jCheckBoxMenuItemDebugReadStatus.setText("Debug  readStatus() ");
        jMenuOptions.add(jCheckBoxMenuItemDebugReadStatus);

        jCheckBoxMenuItemUseEXI.setText("USE EXI (Efficient XML Interchange)");
        jCheckBoxMenuItemUseEXI.addActionListener(formListener);
        jMenuOptions.add(jCheckBoxMenuItemUseEXI);

        jCheckBoxMenuItemUseReadStatusThread.setText("Use seperate read status thread.");
        jCheckBoxMenuItemUseReadStatusThread.addActionListener(formListener);
        jMenuOptions.add(jCheckBoxMenuItemUseReadStatusThread);

        jMenuBarReplaceCommandState.add(jMenuOptions);

        setJMenuBar(jMenuBarReplaceCommandState);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jPanel3, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                            .addComponent(jPanel5, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jPanel6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)))
                .addContainerGap())
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jPanel5, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                        .addComponent(jPanel6, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addGap(6, 6, 6))
                    .addComponent(jPanel1, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addComponent(jPanel3, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(0, 0, 0))
        );

        pack();
    }

    // Code for dispatching events from components to event handlers.

    private class FormListener implements java.awt.event.ActionListener, java.awt.event.MouseListener {
        FormListener() {}
        public void actionPerformed(java.awt.event.ActionEvent evt) {
            if (evt.getSource() == jButtonConnect) {
                PendantClient.this.jButtonConnectActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonDisconnect) {
                PendantClient.this.jButtonDisconnectActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonEnd) {
                PendantClient.this.jButtonEndActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonInit) {
                PendantClient.this.jButtonInitActionPerformed(evt);
            }
            else if (evt.getSource() == jCheckBoxPoll) {
                PendantClient.this.jCheckBoxPollActionPerformed(evt);
            }
            else if (evt.getSource() == jTextFieldPollTime) {
                PendantClient.this.jTextFieldPollTimeActionPerformed(evt);
            }
            else if (evt.getSource() == jTextFieldJointJogIncrement) {
                PendantClient.this.jTextFieldJointJogIncrementActionPerformed(evt);
            }
            else if (evt.getSource() == jTextFieldXYZJogIncrement) {
                PendantClient.this.jTextFieldXYZJogIncrementActionPerformed(evt);
            }
            else if (evt.getSource() == jTextFieldRPYJogIncrement) {
                PendantClient.this.jTextFieldRPYJogIncrementActionPerformed(evt);
            }
            else if (evt.getSource() == jTextFieldJogTime) {
                PendantClient.this.jTextFieldJogTimeActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonMoveTo) {
                PendantClient.this.jButtonMoveToActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonMoveToCurrent) {
                PendantClient.this.jButtonMoveToCurrentActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonProgramPause) {
                PendantClient.this.jButtonProgramPauseActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonProgramAbort) {
                PendantClient.this.jButtonProgramAbortActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonEditProgramItem) {
                PendantClient.this.jButtonEditProgramItemActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonDeletProgramItem) {
                PendantClient.this.jButtonDeletProgramItemActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonAddProgramItem) {
                PendantClient.this.jButtonAddProgramItemActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonProgramRun) {
                PendantClient.this.jButtonProgramRunActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonResume) {
                PendantClient.this.jButtonResumeActionPerformed(evt);
            }
            else if (evt.getSource() == jButtonPlotProgramItem) {
                PendantClient.this.jButtonPlotProgramItemActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItemOpenXmlCommandInstance) {
                PendantClient.this.jMenuItemOpenXmlCommandInstanceActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItemOpenXmlProgram) {
                PendantClient.this.jMenuItemOpenXmlProgramActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItemSaveProgramAs) {
                PendantClient.this.jMenuItemSaveProgramAsActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItemSavePoseList) {
                PendantClient.this.jMenuItemSavePoseListActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItemExit) {
                PendantClient.this.jMenuItemExitActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItemXPathQuery) {
                PendantClient.this.jMenuItemXPathQueryActionPerformed(evt);
            }
            else if (evt.getSource() == jCheckBoxMenuItemPlotXYZ) {
                PendantClient.this.jCheckBoxMenuItemPlotXYZActionPerformed(evt);
            }
            else if (evt.getSource() == jCheckBoxMenuItemJoints) {
                PendantClient.this.jCheckBoxMenuItemJointsActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItemRunTest) {
                PendantClient.this.jMenuItemRunTestActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItemPoseList3DPlot) {
                PendantClient.this.jMenuItemPoseList3DPlotActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItemOpenStatusLog) {
                PendantClient.this.jMenuItemOpenStatusLogActionPerformed(evt);
            }
            else if (evt.getSource() == jMenuItemSetSchemaFiles) {
                PendantClient.this.jMenuItemSetSchemaFilesActionPerformed(evt);
            }
            else if (evt.getSource() == jCheckBoxMenuItemUseEXI) {
                PendantClient.this.jCheckBoxMenuItemUseEXIActionPerformed(evt);
            }
            else if (evt.getSource() == jCheckBoxMenuItemUseReadStatusThread) {
                PendantClient.this.jCheckBoxMenuItemUseReadStatusThreadActionPerformed(evt);
            }
        }

        public void mouseClicked(java.awt.event.MouseEvent evt) {
        }

        public void mouseEntered(java.awt.event.MouseEvent evt) {
        }

        public void mouseExited(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == jLabelJogMinus) {
                PendantClient.this.jLabelJogMinusMouseExited(evt);
            }
            else if (evt.getSource() == jLabelJogPlus) {
                PendantClient.this.jLabelJogPlusMouseExited(evt);
            }
            else if (evt.getSource() == jLabelJogPlus1) {
                PendantClient.this.jLabelJogPlus1MouseExited(evt);
            }
            else if (evt.getSource() == jLabelJogMinus1) {
                PendantClient.this.jLabelJogMinus1MouseExited(evt);
            }
        }

        public void mousePressed(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == jPanelJogMinus) {
                PendantClient.this.jPanelJogMinusMousePressed(evt);
            }
            else if (evt.getSource() == jLabelJogMinus) {
                PendantClient.this.jLabelJogMinusMousePressed(evt);
            }
            else if (evt.getSource() == jLabelJogPlus) {
                PendantClient.this.jLabelJogPlusMousePressed(evt);
            }
            else if (evt.getSource() == jLabelJogPlus1) {
                PendantClient.this.jLabelJogPlus1MousePressed(evt);
            }
            else if (evt.getSource() == jPanelJogMinus1) {
                PendantClient.this.jPanelJogMinus1MousePressed(evt);
            }
            else if (evt.getSource() == jLabelJogMinus1) {
                PendantClient.this.jLabelJogMinus1MousePressed(evt);
            }
        }

        public void mouseReleased(java.awt.event.MouseEvent evt) {
            if (evt.getSource() == jLabelJogMinus) {
                PendantClient.this.jLabelJogMinusMouseReleased(evt);
            }
            else if (evt.getSource() == jLabelJogPlus) {
                PendantClient.this.jLabelJogPlusMouseReleased(evt);
            }
            else if (evt.getSource() == jLabelJogPlus1) {
                PendantClient.this.jLabelJogPlus1MouseReleased(evt);
            }
            else if (evt.getSource() == jLabelJogMinus1) {
                PendantClient.this.jLabelJogMinus1MouseReleased(evt);
            }
        }
    }// </editor-fold>//GEN-END:initComponents

    private final static File statSchemasFile = new File(System.getProperty("user.home"),
            ".crcljava_pendantclient_stat_schemas.txt");

    private final static File cmdSchemasFile = new File(System.getProperty("user.home"),
            ".crcljava_pendantclient_cmd_schemas.txt");

    private final static File programSchemasFile = new File(System.getProperty("user.home"),
            ".crcljava_pendantclient_cmd_schemas.txt");

    private boolean showing_message = false;
    private volatile long last_message_show_time = 0;

    public void showMessage(final String s) {
        if (showDebugMessage(s)) {
            return;
        }

        if (showing_message) {
            return;
        }
        showing_message = true;
        java.awt.EventQueue.invokeLater(new Runnable() {

            @Override
            public void run() {
                long t = System.currentTimeMillis();
                if (t - last_message_show_time > 5000) {
                    last_message_show_time = System.currentTimeMillis();
                    MultiLineStringJPanel.showText(s, PendantClient.this, "Message from Client", true);
                }
                last_message_show_time = System.currentTimeMillis();
                showing_message = false;
            }
        });
    }

    @Override
    public boolean showDebugMessage(final String s) {
        final String sWithThread = "Thread:" + Thread.currentThread().getName()+" "+s;
        LOGGER.log(Level.FINE, sWithThread);
        if (!this.isVisible()) {
            return true;
        }
        java.awt.EventQueue.invokeLater(new Runnable() {
            @Override
            public void run() {
                jTextAreaErrors.setText(jTextAreaErrors.getText() + "\n" + sWithThread);
            }
        });
        return false;
    }


    public void showMessage(Throwable t) {
        this.showMessage(t.toString());
    }

    double last_t_pos_logged = 0;

    final Map<BigInteger, BigDecimal> last_joints = new HashMap<>();

    private boolean jointsChanged(List<JointStatusType> jsl) {
        if (jsl.size() != last_joints.values().size()) {
            return true;
        }
        for (JointStatusType jst : jsl) {
            BigDecimal D = last_joints.get(jst.getJointNumber());
            if (null == D) {
                return true;
            }
            if (!D.equals(jst.getJointPosition())) {
                return true;
            }
        }
        return false;
    }

    private void copyJointPositions(List<JointStatusType> jsl) {
        this.last_joints.clear();
        for (JointStatusType jst : jsl) {
            this.last_joints.put(jst.getJointNumber(), jst.getJointPosition());
        }
    }

    public void setStatus(CRCLStatusType _status) {
        internal.setStatus(_status);
    }

    public void checkXmlQuery(CRCLSocket crclSocket) {
        if (null != this.xqJFrame && this.xqJFrame.isUpdateAutomaticallySelected()) {
            String q = this.xqJFrame.getQuery();
            if (q != null && q.length() > 0) {
                xqJFrame.runQuery(q, crclSocket.getLastStatusString());
            }
        }
    }

    public void finishConnect() {
        this.jButtonConnect.setEnabled(false);
        this.jButtonDisconnect.setEnabled(true);
        this.jButtonEnd.setEnabled(true);
        this.jButtonInit.setEnabled(true);
        if (this.jCheckBoxPoll.isSelected()) {
            this.startPollTimer();
        }
    }

    @Override
    public void finishSetStatus() {
        java.awt.EventQueue.invokeLater(new Runnable() {

            @Override
            public void run() {
                PendantClient.this.finishSetStatusPriv();
            }
        });
    }

    private void finishSetStatusPriv() {
        if (null != internal.getStatus() && null != internal.getStatus().getCommandStatus()) {
            CommandStatusType ccst = internal.getStatus().getCommandStatus();
            if (null != ccst) {
                if (null != ccst.getCommandID()) {
                    this.jTextFieldStatCmdID.setText(ccst.getCommandID().toString());
                }
                if (null != ccst.getCommandState()) {
                    this.jTextFieldStatus.setText(ccst.getCommandState().toString());
                }
                this.jTextFieldStatusID.setText(ccst.getStatusID().toString());
            }
            JointStatusesType jsst = internal.getStatus().getJointStatuses();
            if (jsst != null) {
                List<JointStatusType> jsl = jsst.getJointStatus();
                boolean joints_changed = this.jointsChanged(jsl);
                if (joints_changed) {
                    this.copyJointPositions(jsl);
                    DefaultTableModel tm = (DefaultTableModel) this.jTableJoints.getModel();
                    double t = System.currentTimeMillis();
                    tm.setRowCount(jsl.size());
                    for (JointStatusType js : jsl) {
                        int jn = js.getJointNumber().intValue();
                        if (null != js.getJointVelocity()) {
                            tm.setValueAt(js.getJointVelocity().doubleValue(), jn - 1, 2);
                        }
                        if (null != js.getJointTorqueOrForce()) {
                            tm.setValueAt(js.getJointTorqueOrForce().doubleValue(), jn - 1, 3);
                        }
                        if (null == js.getJointPosition()) {
//                            tm.setValueAt(Double.NaN, jn-1,1);
                            continue;
                        }

                        double pos = js.getJointPosition().doubleValue();
                        tm.setValueAt(jn, jn - 1, 0);
                        tm.setValueAt(pos, jn - 1, 1);
                        if (this.jCheckBoxMenuItemJoints.isSelected()) {
                            if (null == this.jointsPlotter) {
                                jointsPlotter = new plotterJFrame();
                                jointsPlotter.setTitle("JOINTS");
                                jointsPlotter.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                                jointsPlotter.setVisible(true);
                            }
                            String pname = "joint[" + jn + "]";
                            PlotData pd = this.jointsPlotter.getPlotByName(pname);
                            if (null == pd) {
                                pd = new PlotData();
                                pd.name = pname;
                                this.jointsPlotter.AddPlot(pd, pname);
                            }
                            this.jointsPlotter.AddPointToPlot(pd, t, pos, rootPaneCheckingEnabled);
                            if (pd.get_num_points() < 100) {
                                this.jointsPlotter.FitToGraph();
                            }
                        }
                    }
                    if (null != this.jointsPlotter) {
                        this.jointsPlotter.ScrollRight();
                    }
                }
            }
            PoseType p = internal.getStatus().getPose();
            if (null != p) {
                updatePoseTable(p, this.jTablePose);
                PointType pt = p.getPoint();
                if (this.jCheckBoxMenuItemPlotXYZ.isSelected()) {
                    if (null == xyzPlotter) {
                        xyzPlotter = new plotterJFrame();
                        xyzPlotter.setTitle("XYZ");
                        xyzPlotter.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
                        xyzPlotter.setVisible(true);
                    }
                    double t = (double) System.currentTimeMillis();
//                    XMLGregorianCalendar xgc = p.getTimestamp();
//                    if (null != xgc) {
//                        double old_t = t;
//                        t = (double) xgc.toGregorianCalendar().getTime().getTime();
//                    }
                    if (t > this.last_t_pos_logged) {
                        PlotData xpd = xyzPlotter.getPlotByName("x");
                        if (null == xpd) {
                            xpd = new PlotData();
                            xpd.name = "x";
                            xyzPlotter.AddPlot(xpd, "x");
                        }
                        double x = pt.getX().doubleValue();
                        xyzPlotter.AddPointToPlot(xpd, t, x, true);
                        PlotData ypd = xyzPlotter.getPlotByName("y");
                        if (null == ypd) {
                            ypd = new PlotData();
                            ypd.name = "y";
                            xyzPlotter.AddPlot(xpd, "y");
                        }
                        double y = pt.getY().doubleValue();
                        xyzPlotter.AddPointToPlot(ypd, t, y, true);
                        PlotData zpd = xyzPlotter.getPlotByName("z");
                        if (null == zpd) {
                            zpd = new PlotData();
                            zpd.name = "x";
                            xyzPlotter.AddPlot(zpd, "z");
                        }
                        double z = pt.getZ().doubleValue();
                        xyzPlotter.AddPointToPlot(zpd, t, z, true);
                        if (xpd.get_num_points() < 100) {
                            xyzPlotter.FitToGraph();
                        }
                        xyzPlotter.ScrollRight();
                        xyzPlotter.repaint();
                        this.last_t_pos_logged = t;
                    }
                }

            }
        }
    }

    private void updatePoseTable(PoseType p, JTable jTable) {
        try {
            DefaultTableModel tm = (DefaultTableModel) jTable.getModel();
            PointType pt = p.getPoint();
            if (null != pt) {
                tm.setValueAt(pt.getX().doubleValue(), 0, 1);
                tm.setValueAt(pt.getY().doubleValue(), 1, 1);
                tm.setValueAt(pt.getZ().doubleValue(), 2, 1);
            }
            VectorType xv = p.getXAxis();
            if (null != xv) {
                tm.setValueAt(xv.getI().doubleValue(), 3, 1);
                tm.setValueAt(xv.getJ().doubleValue(), 4, 1);
                tm.setValueAt(xv.getK().doubleValue(), 5, 1);
            }
            VectorType zv = p.getZAxis();
            if (null != zv) {
                tm.setValueAt(zv.getI().doubleValue(), 6, 1);
                tm.setValueAt(zv.getJ().doubleValue(), 7, 1);
                tm.setValueAt(zv.getK().doubleValue(), 8, 1);
            }
            PmRpy rpy = CRCLPosemath.toPmRpy(p);
            tm.setValueAt(Math.toDegrees(rpy.r), 9, 1);
            tm.setValueAt(Math.toDegrees(rpy.p), 10, 1);
            tm.setValueAt(Math.toDegrees(rpy.y), 11, 1);
        } catch (PmException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    private void disconnect() {
        internal.disconnect();
    }

    public void finishDisconnect() {
        this.jButtonConnect.setEnabled(true);
        this.jButtonDisconnect.setEnabled(false);
        this.jButtonEnd.setEnabled(false);
        this.jButtonInit.setEnabled(false);
        this.stopPollTimer();
    }

    private final PendantClientInner internal;

    public boolean isConnected() {
        return internal.isConnected();
    }
    
    public void connect(String _host, int _port) {
        internal.connect(_host, _port);
    }

    private void jButtonConnectActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonConnectActionPerformed
        this.connect(this.jTextFieldHost.getText(), Integer.valueOf(this.jTextFieldPort.getText()));
    }//GEN-LAST:event_jButtonConnectActionPerformed

    private void jButtonDisconnectActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonDisconnectActionPerformed
        this.disconnect();
    }//GEN-LAST:event_jButtonDisconnectActionPerformed

    private void jButtonInitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonInitActionPerformed
        InitCanonType init = new InitCanonType();
        internal.incAndSendCommand(init);
    }//GEN-LAST:event_jButtonInitActionPerformed


    private void jButtonEndActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonEndActionPerformed
        EndCanonType end = new EndCanonType();
        internal.incAndSendCommand(end);
    }//GEN-LAST:event_jButtonEndActionPerformed

    private void jPanelJogMinusMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jPanelJogMinusMousePressed
//        ActuateJointsType jog = new ActuateJointsType();
//        cmdId = cmdId.shift(BigInteger.ONE);
//        jog.setCommandID(cmdId);
//        ActuateJointType joint = new ActuateJointType();
//        List<ActuateJointType> l = jog.getActuateJoint();
//        if(l == null) {
//            l = new ArrayList<>();
//        }
//        l.shift(joint);
//        joint.setActuate(true);
//        
//        this.cmd_instance.setCRCLCommand(jog);
//        this.sendCommand();
    }//GEN-LAST:event_jPanelJogMinusMousePressed

    private void jMenuItemExitActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemExitActionPerformed
        System.exit(0);
    }//GEN-LAST:event_jMenuItemExitActionPerformed

//    JointControlModeEnumType jcme = null;
//
//    private void setJointControlModes(JointControlModeEnumType _jcme) {
//        if (this.jcme != _jcme) {
//            SetJointControlModesType setjcm = new SetJointControlModesType();
//            List<JointControlModeType> ljcm = setjcm.getJointControlMode();
//            JointStatusesType jsst = internal.getStatus().getJointStatuses();
//            if (jsst != null) {
//                List<JointStatusType> jsl = jsst.getJointStatus();
//                for (JointStatusType js : jsl) {
//                    JointControlModeType jcm = new JointControlModeType();
//                    jcm.setMode(_jcme);
//                    jcm.setJointNumber(js.getJointNumber());
//                    ljcm.shift(jcm);
//                }
//            }
//            cmdId = cmdId.shift(BigInteger.ONE);
//            setjcm.setCommandID(cmdId);
//            this.cmd_instance.setCRCLCommand(setjcm);
//            this.sendCommand();
//            this.jcme = _jcme;
//        }
//    }
    javax.swing.Timer jog_timer = null;

    private void jogStart(final double increment) {
        if (null == internal.getCRCLSocket()
                || null == internal.getStatus()) {
            showMessage("Can not send command when not connected.");
            return;
        }
//        this.setJointControlModes(JointControlModeEnumType.POSITION);
        final int index = this.jComboBox1.getSelectedIndex() + 1;
        if (null != jog_timer) {
            jog_timer.stop();
            jog_timer = null;
        }
        jog_timer = new javax.swing.Timer(internal.getJogInterval(), new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    final JointStatusType js = CRCLSocket.getJointStatus(internal.getStatus(), index);
                    if (null == js) {
                        showMessage("Can't jog without joint position internal.getStatus() for joint " + index);
                        return;
                    }
                    if (internal.getStatus().getCommandStatus().getCommandState() == CommandStateEnumType.ERROR) {
                        jogStop();
                    }
                    ActuateJointsType ajst = new ActuateJointsType();
                    List<ActuateJointType> ajl = ajst.getActuateJoint();
                    ActuateJointType aj = new ActuateJointType();
                    aj.setJointNumber(js.getJointNumber());
                    aj.setJointPosition(js.getJointPosition().add(BigDecimal.valueOf(increment)));
                    JointSpeedAccelType jsa = new JointSpeedAccelType();
                    aj.setJointDetails(jsa);
                    ajl.add(aj);
                    internal.incAndSendCommand(ajst);
                } catch (Exception ex) {
                    ex.printStackTrace();
                    jogStop();
                }
            }
        });
        jog_timer.start();
    }

    private double rpyJogIncrement = 3.0;

    /**
     * Get the value of rpyJogIncrement
     *
     * @return the value of rpyJogIncrement
     */
    public double getRpyJogIncrement() {
        return rpyJogIncrement;
    }

    /**
     * Set the value of rpyJogIncrement
     *
     * @param rpyJogIncrement new value of rpyJogIncrement
     */
    public void setRpyJogIncrement(double rpyJogIncrement) {
        this.rpyJogIncrement = rpyJogIncrement;
    }

    private void jogWorldStart(double sign) {
        if (null == internal.getStatus()
                || null == internal.getStatus()) {
            showMessage("Can not send command when not connected.");
            return;
        }
//        this.setJointControlModes(JointControlModeEnumType.POSITION);
        final String axis = (String) this.jComboBoxXYZRPY.getSelectedItem();
        double tmpinc = 1.0;
        sign = Math.signum(sign);
        switch (axis) {
            case "X":
            case "Y":
            case "Z":
                tmpinc = internal.getXyzJogIncrement() * sign;
                break;

            case "Roll":
            case "Pitch":
            case "Yaw":
                tmpinc = Math.toRadians(this.rpyJogIncrement) * sign;
                break;
        }
        final BigDecimal axisIncrement = BigDecimal.valueOf(tmpinc);
        final double inc = tmpinc;
        if (null != jog_timer) {
            jog_timer.stop();
            jog_timer = null;
        }
        jog_timer = new javax.swing.Timer(internal.getJogInterval(), new ActionListener() {

            @Override
            public void actionPerformed(ActionEvent e) {
                try {
                    if (internal.getStatus().getCommandStatus().getCommandState() == CommandStateEnumType.ERROR) {
                        jogStop();
                    }
                    MoveToType moveToType = new MoveToType();
                    PoseType endPos = new PoseType();
                    endPos.setPoint(new PointType());
                    endPos.setXAxis(new VectorType());
                    endPos.setZAxis(new VectorType());
                    moveToType.setEndPosition(endPos);
                    moveToType.getEndPosition().getPoint().setX(internal.getStatus().getPose().getPoint().getX());
                    moveToType.getEndPosition().getPoint().setY(internal.getStatus().getPose().getPoint().getY());
                    moveToType.getEndPosition().getPoint().setZ(internal.getStatus().getPose().getPoint().getZ());
                    moveToType.getEndPosition().getXAxis().setI(internal.getStatus().getPose().getXAxis().getI());
                    moveToType.getEndPosition().getXAxis().setJ(internal.getStatus().getPose().getXAxis().getJ());
                    moveToType.getEndPosition().getXAxis().setK(internal.getStatus().getPose().getXAxis().getK());
                    moveToType.getEndPosition().getZAxis().setI(internal.getStatus().getPose().getZAxis().getI());
                    moveToType.getEndPosition().getZAxis().setJ(internal.getStatus().getPose().getZAxis().getJ());
                    moveToType.getEndPosition().getZAxis().setK(internal.getStatus().getPose().getZAxis().getK());
                    switch (axis) {
                        case "X":
                            moveToType.getEndPosition().getPoint().setX(internal.getStatus().getPose().getPoint().getX().add(axisIncrement));
                            break;

                        case "Y":
                            moveToType.getEndPosition().getPoint().setY(internal.getStatus().getPose().getPoint().getY().add(axisIncrement));
                            break;

                        case "Z":
                            moveToType.getEndPosition().getPoint().setZ(internal.getStatus().getPose().getPoint().getZ().add(axisIncrement));
                            break;

                        case "Roll":
                            incrementRoll(moveToType, inc);
                            break;

                        case "Pitch":
                            incrementPitch(moveToType, inc);
                            break;

                        case "Yaw":
                            incrementYaw(moveToType, inc);
                            break;

                    }
                    internal.incAndSendCommand(moveToType);
                } catch (Exception ex) {
                    ex.printStackTrace();
                    jogStop();
                }
            }

            private void incrementYaw(MoveToType moveToType, final double inc) throws PmException {
                PmRotationMatrix pm = CRCLPosemath.toPmRotationMatrix(internal.getStatus().getPose());
                PmRpy rpy = Posemath.toRpy(pm);
                rpy.y += inc;
                PmRotationVector pm2 = Posemath.toRot(rpy);
                PoseType nextPose = CRCLPosemath.toPoseType(
                        CRCLPosemath.pointToPmCartesian(internal.getStatus().getPose().getPoint()),
                        pm2);
                moveToType.setEndPosition(nextPose);
            }

            private void incrementPitch(MoveToType moveToType, final double inc) throws PmException {
                PmRotationMatrix pm = CRCLPosemath.toPmRotationMatrix(internal.getStatus().getPose());
                PmRpy rpy = Posemath.toRpy(pm);
                rpy.p += inc;
                PmRotationVector pm2 = Posemath.toRot(rpy);
                PoseType nextPose = CRCLPosemath.toPoseType(
                        CRCLPosemath.pointToPmCartesian(internal.getStatus().getPose().getPoint()),
                        pm2);
                moveToType.setEndPosition(nextPose);
            }

            private void incrementRoll(MoveToType moveToType, final double inc) throws PmException {
                PmRotationMatrix pm = CRCLPosemath.toPmRotationMatrix(internal.getStatus().getPose());
                PmRpy rpy = Posemath.toRpy(pm);
                rpy.r += inc;
                PmRotationVector pm2 = Posemath.toRot(rpy);
                PoseType nextPose = CRCLPosemath.toPoseType(
                        CRCLPosemath.pointToPmCartesian(internal.getStatus().getPose().getPoint()),
                        pm2);
                moveToType.setEndPosition(nextPose);
            }
        });
        jog_timer.start();
    }

    private void jogStop() {
        if (null != jog_timer) {
            jog_timer.stop();
            jog_timer = null;
        }
    }

    public void checkPollSelected() {
        if (this.jCheckBoxPoll.isSelected()) {
            this.startPollTimer();
        }
    }

    private void commonJogStop() {
        this.jogStop();
        this.jLabelJogMinus.setBackground(Color.WHITE);
        this.jLabelJogMinus.setForeground(Color.BLACK);
        this.jPanelJogMinus.setBackground(Color.WHITE);
        this.jLabelJogMinus.repaint();
        this.jPanelJogMinus.repaint();
        this.jLabelJogMinus1.setBackground(Color.WHITE);
        this.jLabelJogMinus1.setForeground(Color.BLACK);
        this.jPanelJogMinus1.setBackground(Color.WHITE);
        this.jLabelJogMinus1.repaint();
        this.jPanelJogMinus1.repaint();
        this.jLabelJogPlus.setBackground(Color.WHITE);
        this.jLabelJogPlus.setForeground(Color.BLACK);
        this.jPanelJogPlus.setBackground(Color.WHITE);
        this.jLabelJogPlus.repaint();
        this.jPanelJogPlus.repaint();
        this.jLabelJogPlus1.setBackground(Color.WHITE);
        this.jLabelJogPlus1.setForeground(Color.BLACK);
        this.jPanelJogPlus1.setBackground(Color.WHITE);
        this.jLabelJogPlus1.repaint();
        this.jPanelJogPlus1.repaint();
    }

    private void jLabelJogMinusMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogMinusMousePressed
        this.jogStart(-1.0 * internal.getJogIncrement());
        this.jLabelJogMinus.setBackground(Color.BLACK);
        this.jLabelJogMinus.setForeground(Color.WHITE);
        this.jPanelJogMinus.setBackground(Color.BLACK);
        this.jLabelJogMinus.repaint();
        this.jPanelJogMinus.repaint();
    }//GEN-LAST:event_jLabelJogMinusMousePressed

    private void jLabelJogMinusMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogMinusMouseReleased
        this.commonJogStop();
    }//GEN-LAST:event_jLabelJogMinusMouseReleased

    private void jLabelJogMinusMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogMinusMouseExited
        this.commonJogStop();
    }//GEN-LAST:event_jLabelJogMinusMouseExited

    private void jLabelJogPlusMousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogPlusMousePressed
        this.jogStart(+1.0 * internal.getJogIncrement());
        this.jLabelJogPlus.setBackground(Color.BLACK);
        this.jLabelJogPlus.setForeground(Color.WHITE);
        this.jPanelJogPlus.setBackground(Color.BLACK);
        this.jLabelJogPlus.repaint();
        this.jPanelJogPlus.repaint();
    }//GEN-LAST:event_jLabelJogPlusMousePressed

    private void jLabelJogPlusMouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogPlusMouseReleased
        this.commonJogStop();
    }//GEN-LAST:event_jLabelJogPlusMouseReleased

    private void jLabelJogPlusMouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogPlusMouseExited
        this.commonJogStop();
    }//GEN-LAST:event_jLabelJogPlusMouseExited

    private XpathQueryJFrame xqJFrame = null;
    private void jMenuItemXPathQueryActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemXPathQueryActionPerformed
        if (null == xqJFrame) {
            try {
                xqJFrame = new XpathQueryJFrame();
            } catch (ParserConfigurationException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
        }
        xqJFrame.setVisible(true);
    }//GEN-LAST:event_jMenuItemXPathQueryActionPerformed

    private void jButtonMoveToActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonMoveToActionPerformed
        MoveToType moveto = new MoveToType();
        PoseType p = new PoseType();
        DefaultTableModel tm = (DefaultTableModel) this.jTableMoveToPose.getModel();
        PointType pt = new PointType();
        pt.setX(BigDecimal.valueOf((Double) tm.getValueAt(0, 1)));
        pt.setY(BigDecimal.valueOf((Double) tm.getValueAt(1, 1)));
        pt.setZ(BigDecimal.valueOf((Double) tm.getValueAt(2, 1)));
        VectorType xv = new VectorType();
        xv.setI(BigDecimal.valueOf((Double) tm.getValueAt(3, 1)));
        xv.setJ(BigDecimal.valueOf((Double) tm.getValueAt(4, 1)));
        xv.setK(BigDecimal.valueOf((Double) tm.getValueAt(5, 1)));
        VectorType zv = new VectorType();
        zv.setI(BigDecimal.valueOf((Double) tm.getValueAt(6, 1)));
        zv.setJ(BigDecimal.valueOf((Double) tm.getValueAt(7, 1)));
        zv.setK(BigDecimal.valueOf((Double) tm.getValueAt(8, 1)));
        p.setPoint(pt);
        p.setXAxis(xv);
        p.setZAxis(zv);
        moveto.setEndPosition(p);
        moveto.setMoveStraight(this.jCheckBoxStraight.isSelected());
        internal.incAndSendCommand(moveto);
    }//GEN-LAST:event_jButtonMoveToActionPerformed

    diagapplet.plotter.plotterJFrame xyzPlotter = null;

    diagapplet.plotter.plotterJFrame jointsPlotter = null;

    private void jMenuItemSetSchemaFilesActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemSetSchemaFilesActionPerformed
        JFileChooser jFileChooser = new JFileChooser();
        javax.swing.filechooser.FileFilter[] ffa = jFileChooser.getChoosableFileFilters();
        for (javax.swing.filechooser.FileFilter ff : ffa) {
            jFileChooser.removeChoosableFileFilter(ff);
        }
        jFileChooser.addChoosableFileFilter(new FileNameExtensionFilter("XML Schema file", "xsd"));
        jFileChooser.setMultiSelectionEnabled(true);
        int result = jFileChooser.showOpenDialog(this);
        if (result == JFileChooser.APPROVE_OPTION) {
            File fa[] = jFileChooser.getSelectedFiles();
            internal.setCmdSchema(fa);
            CRCLSocket.saveCmdSchemaFiles(PendantClient.cmdSchemasFile, fa);
            internal.setStatSchema(fa);
            CRCLSocket.saveStatSchemaFiles(PendantClient.statSchemasFile, fa);
            internal.setProgramSchema(fa);
            CRCLSocket.saveProgramSchemaFiles(PendantClient.programSchemasFile, fa);
        }
    }//GEN-LAST:event_jMenuItemSetSchemaFilesActionPerformed

    private void jCheckBoxMenuItemJointsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCheckBoxMenuItemJointsActionPerformed
        if (this.jCheckBoxMenuItemJoints.isSelected()) {
            jointsPlotter = new plotterJFrame();
            jointsPlotter.setTitle("JOINTS");
            jointsPlotter.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            jointsPlotter.setVisible(true);
        }
    }//GEN-LAST:event_jCheckBoxMenuItemJointsActionPerformed

    private void jCheckBoxMenuItemPlotXYZActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCheckBoxMenuItemPlotXYZActionPerformed
        if (this.jCheckBoxMenuItemPlotXYZ.isSelected()) {
            xyzPlotter = new plotterJFrame();
            xyzPlotter.setTitle("XYZ");
            xyzPlotter.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
            xyzPlotter.setVisible(true);
        }
    }//GEN-LAST:event_jCheckBoxMenuItemPlotXYZActionPerformed

    private void jButtonMoveToCurrentActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonMoveToCurrentActionPerformed
        this.updatePoseTable(internal.getStatus().getPose(), this.jTableMoveToPose);
    }//GEN-LAST:event_jButtonMoveToCurrentActionPerformed

    private static final String recent_files_dir = ".crcl_pendant_client_recent_files";

    private void saveRecentCommandInstance(CRCLCommandInstanceType cmd) throws JAXBException, IOException {
        CRCLSocket tmpcs = internal.getTempCRCLSocket();
        String s = tmpcs.commandToPrettyDocString(cmd, true);
        File fDir = new File(System.getProperty("user.home"), recent_files_dir);
        fDir.mkdirs();
        String name = cmd.getCRCLCommand().getClass().getSimpleName();
        int pindex = name.lastIndexOf('.');
        if (pindex > 0 && pindex < name.length()) {
            name = name.substring(pindex + 1);
        }
        File fDir2 = new File(fDir, name);
        fDir2.mkdirs();
        Date dNow = new Date();
        SimpleDateFormat ft
                = new SimpleDateFormat("yyyy-MM-dd_hh_mm_ss_a_zzz_");
        String date_string = ft.format(dNow);
        File f = File.createTempFile(date_string, ".xml", fDir2);
        try (FileWriter fw = new FileWriter(f)) {
            fw.write(s);
        }
    }

    private static final String recent_programs_dir = ".crcl_pendant_client_recent_programs";

    private void saveRecentProgram(File fprog) throws JAXBException, IOException {
        Set<String> pathSet = this.getRecentPrograms();
        if (pathSet.contains(fprog.getCanonicalPath())) {
            return;
        }
        File fDir = new File(System.getProperty("user.home"), recent_programs_dir);
        fDir.mkdirs();
        String name = fprog.getName();
        if (null == name) {
            name = "untitled";
        }
        Date dNow = new Date();
        SimpleDateFormat ft
                = new SimpleDateFormat("yyyy-MM-dd_hh_mm_ss_a_zzz_");
        String date_string = ft.format(dNow);
        File flink = File.createTempFile(name + "_" + date_string, ".txt", fDir);
        try (FileWriter fw = new FileWriter(flink)) {
            fw.write(fprog.getCanonicalPath());
        }
    }

    private void saveRecentCommand(CRCLCommandType cmd) throws JAXBException, IOException {
        CRCLCommandInstanceType instanceForSave = new CRCLCommandInstanceType();
        instanceForSave.setCRCLCommand(cmd);
        this.saveRecentCommandInstance(instanceForSave);
    }

    private void browseOpenCommandXml() {
        JFileChooser chooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "XML Instance Files", "xml");
        chooser.setFileFilter(filter);
        int returnVal = chooser.showOpenDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            try {
                File f = chooser.getSelectedFile();
                openXmlInstanceFile(f);
            } catch (SAXException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
                this.showMessage(ex);
            } catch (IOException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } catch (XPathExpressionException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } catch (ParserConfigurationException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } catch (JAXBException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
                this.showMessage(ex);
            }
        }
    }

    private void browseOpenProgramXml() {
        JFileChooser chooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "XML Program Files", "xml");
        chooser.setFileFilter(filter);
        int returnVal = chooser.showOpenDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            try {
                File f = chooser.getSelectedFile();
                openXmlProgramFile(f);
            } catch (SAXException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
                this.showMessage(ex);
            } catch (IOException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } catch (XPathExpressionException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } catch (ParserConfigurationException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } catch (JAXBException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
                this.showMessage(ex);
            }
        }
    }

    @Override
    public CRCLProgramType editProgram(CRCLProgramType program) {
        internal.getXpu().setSchemaFiles(internal.getProgramSchemaFiles());
        program = ObjTableJPanel.editObject(program, internal.getXpu(),
                internal.getCheckProgramValidPredicate());
        return program;
    }

    private void openXmlInstanceFile(File f) throws ParserConfigurationException, JAXBException, XPathExpressionException, IOException, SAXException {
        String s = internal.getXpu().queryXml(f, "/");
        CRCLCommandInstanceType cmdInstance
                = internal.getCRCLSocket().stringToCommand(s, this.jCheckBoxMenuItemValidateXml.isSelected());
        CRCLCommandType cmd = cmdInstance.getCRCLCommand();
        cmd = ObjTableJPanel.editObject(cmd, internal.getXpu(),
                internal.getCheckCommandValidPredicate());
        internal.incAndSendCommand(cmd);
        this.saveRecentCommand(cmd);
    }

    private String tableCommandType(CRCLCommandType cmd) {
        String clssName = cmd.getClass().getSimpleName();
        String prefix = "crcl.base.";
        if (clssName.startsWith(prefix)) {
            return clssName.substring(prefix.length());
        }
        return clssName;
    }

    public void showProgram(CRCLProgramType program) {
        DefaultTableModel dtm = (DefaultTableModel) this.jTableProgram.getModel();
        BigInteger maxCmdId = BigInteger.ONE;
        InitCanonType init = program.getInitCanon();
        List<MiddleCommandType> middleCommands = program.getMiddleCommand();
        dtm.setRowCount(2 + middleCommands.size());
        if (init.getCommandID() == null) {
            init.setCommandID(maxCmdId);
        } else {
            maxCmdId = maxCmdId.max(init.getCommandID());
        }
        dtm.setValueAt(init.getCommandID().longValue(), 0, 0);
        dtm.setValueAt(tableCommandType(init), 0, 1);
        dtm.setValueAt(-1, 0, 2);
        dtm.setValueAt(0.0, 0, 2);  
        for (int i = 0; i < middleCommands.size(); i++) {
            MiddleCommandType middleCommand = middleCommands.get(i);
            if (null == middleCommand) {
                showDebugMessage("middleCommands contains null at " + i);
                continue;
            }
            maxCmdId = maxCmdId.add(BigInteger.ONE);
            if (middleCommand.getCommandID() == null || middleCommand.getCommandID().compareTo(maxCmdId) < 0) {
                middleCommand.setCommandID(maxCmdId);
            }
            maxCmdId = maxCmdId.max(middleCommand.getCommandID());
            dtm.setValueAt(middleCommand.getCommandID().longValue(), i + 1, 0);
            dtm.setValueAt(tableCommandType(middleCommand), i + 1, 1);
            dtm.setValueAt(-1, i + 1, 2);
            dtm.setValueAt(0.0, i + 1, 3);
        }
        EndCanonType endCommand = program.getEndCanon();
        maxCmdId = maxCmdId.add(BigInteger.ONE);
        if (endCommand.getCommandID() == null || endCommand.getCommandID().compareTo(maxCmdId) < 0) {
            endCommand.setCommandID(maxCmdId);
        }
        dtm.setValueAt(endCommand.getCommandID().longValue(), 1 + middleCommands.size(), 0);
        dtm.setValueAt(tableCommandType(endCommand), 1 + middleCommands.size(), 1);
        dtm.setValueAt(-1, 1 + middleCommands.size(), 2);
        dtm.setValueAt(0.0, 1 + middleCommands.size(), 3);
    }
    private void jMenuItemOpenXmlCommandInstanceActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemOpenXmlCommandInstanceActionPerformed
        this.browseOpenCommandXml();
    }//GEN-LAST:event_jMenuItemOpenXmlCommandInstanceActionPerformed

    private void jMenuItemOpenXmlProgramActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemOpenXmlProgramActionPerformed
        this.browseOpenProgramXml();
    }//GEN-LAST:event_jMenuItemOpenXmlProgramActionPerformed

    javax.swing.Timer pollTimer = null;

    private void startPollTimer() {
        pollTimer = new javax.swing.Timer(internal.getPoll_ms(), new ActionListener() {

            private boolean toggler =false;
            
            @Override
            public void actionPerformed(ActionEvent e) {
                
                if(!toggler) {
                    internal.requestStatus();
                    if(!isUseReadStatusThreadSelected()) {
                        toggler = true;
                    }
                } else {
                    if(!isUseReadStatusThreadSelected()) {
                        internal.readStatus();
                    }
                    toggler = false;
                }
            }
        });
        pollTimer.start();
    }

    @Override
    public void stopPollTimer() {
        if (pollTimer != null) {
            pollTimer.stop();
            pollTimer = null;
        }
    }

    private void jCheckBoxPollActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCheckBoxPollActionPerformed
        this.stopPollTimer();
        if (this.jCheckBoxPoll.isSelected() && null != internal.getCRCLSocket()) {
            this.startPollTimer();
        }
    }//GEN-LAST:event_jCheckBoxPollActionPerformed

    private void jTextFieldPollTimeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextFieldPollTimeActionPerformed
        int new_poll_ms = Integer.valueOf(this.jTextFieldPollTime.getText());
        internal.setPoll_ms(new_poll_ms);
        this.stopPollTimer();
        if (this.jCheckBoxPoll.isSelected()) {
            this.startPollTimer();
        }
    }//GEN-LAST:event_jTextFieldPollTimeActionPerformed

    private void jLabelJogPlus1MousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogPlus1MousePressed
        this.jogWorldStart(+1.0);
        this.jLabelJogPlus1.setBackground(Color.BLACK);
        this.jLabelJogPlus1.setForeground(Color.WHITE);
        this.jPanelJogPlus1.setBackground(Color.BLACK);
        this.jLabelJogPlus1.repaint();
        this.jPanelJogPlus1.repaint();
    }//GEN-LAST:event_jLabelJogPlus1MousePressed

    private void jLabelJogPlus1MouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogPlus1MouseReleased
        this.commonJogStop();
    }//GEN-LAST:event_jLabelJogPlus1MouseReleased

    private void jLabelJogPlus1MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogPlus1MouseExited
        this.commonJogStop();
    }//GEN-LAST:event_jLabelJogPlus1MouseExited

    private void jLabelJogMinus1MousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogMinus1MousePressed
        this.jogWorldStart(-1.0);
        this.jLabelJogMinus1.setBackground(Color.BLACK);
        this.jLabelJogMinus1.setForeground(Color.WHITE);
        this.jPanelJogMinus1.setBackground(Color.BLACK);
        this.jLabelJogMinus1.repaint();
        this.jPanelJogMinus1.repaint();
    }//GEN-LAST:event_jLabelJogMinus1MousePressed

    private void jLabelJogMinus1MouseReleased(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogMinus1MouseReleased
        this.commonJogStop();
    }//GEN-LAST:event_jLabelJogMinus1MouseReleased

    private void jLabelJogMinus1MouseExited(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jLabelJogMinus1MouseExited
        this.commonJogStop();
    }//GEN-LAST:event_jLabelJogMinus1MouseExited

    private void jPanelJogMinus1MousePressed(java.awt.event.MouseEvent evt) {//GEN-FIRST:event_jPanelJogMinus1MousePressed
        this.jogWorldStart(-1.0);
        this.jLabelJogMinus1.setBackground(Color.BLACK);
        this.jLabelJogMinus1.setForeground(Color.WHITE);
        this.jPanelJogMinus1.setBackground(Color.BLACK);
        this.jLabelJogMinus1.repaint();
        this.jPanelJogMinus1.repaint();
    }//GEN-LAST:event_jPanelJogMinus1MousePressed

    private void jTextFieldJointJogIncrementActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextFieldJointJogIncrementActionPerformed
        internal.setJogIncrement(Double.valueOf(this.jTextFieldJointJogIncrement.getText()));
    }//GEN-LAST:event_jTextFieldJointJogIncrementActionPerformed

    private void jTextFieldXYZJogIncrementActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextFieldXYZJogIncrementActionPerformed
        internal.setXyzJogIncrement(Double.valueOf(this.jTextFieldXYZJogIncrement.getText()));
    }//GEN-LAST:event_jTextFieldXYZJogIncrementActionPerformed

    private void jTextFieldRPYJogIncrementActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextFieldRPYJogIncrementActionPerformed
        this.setRpyJogIncrement(Double.valueOf(this.jTextFieldRPYJogIncrement.getText()));
    }//GEN-LAST:event_jTextFieldRPYJogIncrementActionPerformed

    private void jTextFieldJogTimeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextFieldJogTimeActionPerformed
        internal.setJogIncrement(Double.valueOf(this.jTextFieldJogTime.getText()));
    }//GEN-LAST:event_jTextFieldJogTimeActionPerformed

    private void jMenuItemRunTestActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemRunTestActionPerformed
        internal.startRunTestThread();
    }//GEN-LAST:event_jMenuItemRunTestActionPerformed

    private void clearProgramTimesDistances() {
        DefaultTableModel dtm = (DefaultTableModel) this.jTableProgram.getModel();
        for (int i = 0; i < dtm.getRowCount(); i++) {
            dtm.setValueAt(-1, i, 2);
            dtm.setValueAt(0.0, i, 3);
        }
    }

    private void jButtonProgramRunActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonProgramRunActionPerformed
        this.clearProgramTimesDistances();
        internal.startRunProgramThread();
        this.jButtonResume.setEnabled(internal.isPaused());
        this.jButtonProgramPause.setEnabled(internal.isRunningProgram());
    }//GEN-LAST:event_jButtonProgramRunActionPerformed

    private void jButtonResumeActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonResumeActionPerformed
        internal.unpause();
        this.jButtonResume.setEnabled(internal.isPaused());
        this.jButtonProgramPause.setEnabled(internal.isRunningProgram());
    }//GEN-LAST:event_jButtonResumeActionPerformed

    private void jButtonProgramPauseActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonProgramPauseActionPerformed
        internal.pause();
        this.jButtonResume.setEnabled(internal.isPaused());
        this.jButtonProgramPause.setEnabled(internal.isRunningProgram());
    }//GEN-LAST:event_jButtonProgramPauseActionPerformed

    private void jButtonProgramAbortActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonProgramAbortActionPerformed
        internal.abort();
    }//GEN-LAST:event_jButtonProgramAbortActionPerformed

    private void jButtonDeletProgramItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonDeletProgramItemActionPerformed
        int index = this.jTableProgram.getSelectedRow();
        if (index > 0 && index < this.jTableProgram.getRowCount() - 1) {
            internal.getProgram().getMiddleCommand().remove(index - 1);
            this.showProgram(internal.getProgram());
            this.showCurrentProgramLine(index);
        }
    }//GEN-LAST:event_jButtonDeletProgramItemActionPerformed

    private void jButtonEditProgramItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonEditProgramItemActionPerformed
        int index = this.jTableProgram.getSelectedRow();
        if (index > 0 && index < this.jTableProgram.getRowCount() - 1) {
            MiddleCommandType cmdOrig = internal.getProgram().getMiddleCommand().get(index - 1);
            MiddleCommandType cmdEdited
                    = (MiddleCommandType) ObjTableJPanel.editObject(cmdOrig,
                            internal.getXpu(), PendantClient.this.internal.getCheckCommandValidPredicate());
            if (null == cmdEdited) {
                showDebugMessage("Edit Program Item cancelled. cmdEdited == null");
                return;
            }
            internal.getProgram().getMiddleCommand().set(index - 1, cmdEdited);
            this.showProgram(internal.getProgram());
            this.showCurrentProgramLine(index);
        }
    }//GEN-LAST:event_jButtonEditProgramItemActionPerformed

    private void jButtonAddProgramItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonAddProgramItemActionPerformed
        int index = this.jTableProgram.getSelectedRow();
        if (index > 0 && index < this.jTableProgram.getRowCount() - 1) {
            try {
                Class clss = MiddleCommandType.class;
                List<Class> availClasses = getAssignableClasses(clss,
                        ObjTableJPanel.getClasses());
                Class ca[] = availClasses.toArray(new Class[availClasses.size()]);
//               int selected = JOptionPane.showOptionDialog(this,
//                       "Select class of new " + clss.getCanonicalName(),
//                       "new " + clss.getCanonicalName(),
//                       JOptionPane.DEFAULT_OPTION,
//                       JOptionPane.QUESTION_MESSAGE,
//                       null,
//                       ca,
//                       null);
//               if(selected < 0 || selected >= ca.length) {
//                   showDebugMessage("Add Program Item cancelled. invalid class index = "+selected);
//                   return;
//               }
                Class selectedClss = ListChooserJPanel.Choose(this, "Type of new Item", ca, null);
                if (selectedClss == null) {
                    showDebugMessage("Add Program Item cancelled. selectedClss == null");
                    return;
                }
                MiddleCommandType cmdOrig = (MiddleCommandType) selectedClss.newInstance();
                MiddleCommandType cmdEdited
                        = (MiddleCommandType) ObjTableJPanel.editObject(cmdOrig,
                                internal.getXpu(), PendantClient.this.internal.getCheckCommandValidPredicate());
                if (null == cmdEdited) {
                    showDebugMessage("Add Program Item cancelled. cmdEdited == null");
                    return;
                }
                internal.getProgram().getMiddleCommand().add(index - 1, cmdEdited);
                this.showProgram(internal.getProgram());
                this.showCurrentProgramLine(index);
            } catch (InstantiationException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
                showMessage(ex);
            } catch (IllegalAccessException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
                showMessage(ex);
            }
        }
    }//GEN-LAST:event_jButtonAddProgramItemActionPerformed

    private void jMenuItemSaveProgramAsActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemSaveProgramAsActionPerformed
        JFileChooser chooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "XML Program Files", "xml");
        chooser.setFileFilter(filter);
        int returnVal = chooser.showSaveDialog(this);
        if (returnVal == JFileChooser.APPROVE_OPTION) {
            try {
                File f = chooser.getSelectedFile();
                saveXmlProgramFile(f);
            } catch (SAXException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
                this.showMessage(ex);
            } catch (IOException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } catch (XPathExpressionException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } catch (ParserConfigurationException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } catch (JAXBException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
                this.showMessage(ex);
            }
        }
    }//GEN-LAST:event_jMenuItemSaveProgramAsActionPerformed

    private void jMenuItemSavePoseListActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemSavePoseListActionPerformed
       JFileChooser chooser = new JFileChooser();
        FileNameExtensionFilter filter = new FileNameExtensionFilter(
                "Comma-Separated-Values", "csv");
        chooser.setFileFilter(filter);
        int returnVal = chooser.showSaveDialog(this);
        if(returnVal ==  JFileChooser.APPROVE_OPTION) {
           try {
               this.internal.savePoseListToCsvFile(chooser.getSelectedFile().getAbsolutePath());
           } catch (IOException ex) {
               Logger.getLogger(PendantClient.class.getName()).log(Level.SEVERE, null, ex);
           } catch (PmException ex) {
               Logger.getLogger(PendantClient.class.getName()).log(Level.SEVERE, null, ex);
           }
        }
    }//GEN-LAST:event_jMenuItemSavePoseListActionPerformed

    private void jMenuItemPoseList3DPlotActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemPoseList3DPlotActionPerformed
        try {
//            File tmpFile = File.createTempFile("poseList", ".csv");
//            this.internal.savePoseListToCsvFile(tmpFile.getAbsolutePath());
            com.github.wshackle.poselist3dplot.MainJFrame.showPoseList(this.internal.getPoseList());
        } catch (Exception ex) {
            Logger.getLogger(PendantClient.class.getName()).log(Level.SEVERE, null, ex);
        } 
    }//GEN-LAST:event_jMenuItemPoseList3DPlotActionPerformed

    private void jMenuItemOpenStatusLogActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItemOpenStatusLogActionPerformed
        try {
            File tmpFile = File.createTempFile("poseList", ".csv");
            this.internal.savePoseListToCsvFile(tmpFile.getAbsolutePath());
            Desktop.getDesktop().open(tmpFile);
        } catch (IOException ex) {
            Logger.getLogger(PendantClient.class.getName()).log(Level.SEVERE, null, ex);
        } catch (PmException ex) {
            Logger.getLogger(PendantClient.class.getName()).log(Level.SEVERE, null, ex);
        }
    }//GEN-LAST:event_jMenuItemOpenStatusLogActionPerformed

    private void jButtonPlotProgramItemActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButtonPlotProgramItemActionPerformed
        final int index = this.jTableProgram.getSelectedRow();
        if (index > 0 && index < this.jTableProgram.getRowCount() - 1) {
            MiddleCommandType cmdOrig = internal.getProgram().getMiddleCommand().get(index - 1);
            BigInteger id = cmdOrig.getCommandID();
            final List<AnnotatedPose> l =
                    this.internal
                            .getPoseList()
                            .stream()
                            .filter(x -> x.getCmdId().compareTo(id) == 0)
                            .collect(Collectors.toList());
            com.github.wshackle.poselist3dplot.MainJFrame
                    .showPoseList(l);
        }
    }//GEN-LAST:event_jButtonPlotProgramItemActionPerformed

    private void jCheckBoxMenuItemUseEXIActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCheckBoxMenuItemUseEXIActionPerformed
        if(this.isConnected()) {
            this.disconnect();
            this.connect(this.jTextFieldHost.getText(), Integer.valueOf(this.jTextFieldPort.getText()));
        }
    }//GEN-LAST:event_jCheckBoxMenuItemUseEXIActionPerformed

    private void jCheckBoxMenuItemUseReadStatusThreadActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jCheckBoxMenuItemUseReadStatusThreadActionPerformed
        if(this.jCheckBoxMenuItemDebugReadStatus.isSelected()) {
            internal.startStatusReaderThread();
        } else {
            internal.stopStatusReaderThread();
        }
    }//GEN-LAST:event_jCheckBoxMenuItemUseReadStatusThreadActionPerformed

    private static void scrollToVisible(JTable table, int rowIndex, int vColIndex) {
        if (!(table.getParent() instanceof JViewport)) {
            return;
        }
        JViewport viewport = (JViewport) table.getParent();
        Rectangle rect = table.getCellRect(rowIndex, vColIndex, true);
        Point pt = viewport.getViewPosition();
        rect.setLocation(rect.x - pt.x, rect.y - pt.y);
        viewport.scrollRectToVisible(rect);
    }

    private void finishShowCurrentProgramLine(final int line) {
        jTableProgram.clearSelection();
        jTableProgram.getSelectionModel().setSelectionInterval(line, line);
        scrollToVisible(jTableProgram, line, 0);
        jTableProgram.repaint();
        jPanelProgram.revalidate();
        jPanelProgram.repaint();
    }

    @Override
    public void showCurrentProgramLine(final int line) {
        if (line >= this.jTableProgram.getRowCount() || line < 0) {
            return;
        }
        java.awt.EventQueue.invokeLater(new Runnable() {

            @Override
            public void run() {
                finishShowCurrentProgramLine(line);
            }
        });
    }

    @Override
    public boolean isEXISelected() {
        return this.jCheckBoxMenuItemUseEXI.isSelected();
    }

    @Override
    public boolean isUseReadStatusThreadSelected() {
        return this.jCheckBoxMenuItemUseReadStatusThread.isSelected();
    }
    
    

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            LOGGER.log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            LOGGER.log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            LOGGER.log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            LOGGER.log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                try {
                    new PendantClient().setVisible(true);
                } catch (ParserConfigurationException ex) {
                    LOGGER.log(Level.SEVERE, null, ex);
                }
            }
        });
    }

    @Override
    public boolean validateXmlSelected() {
        return this.jCheckBoxMenuItemValidateXml.isSelected();

    }

    @Override
    public boolean replaceStateSelected() {
        return this.jCheckBoxMenuItemReplaceState.isSelected();
    }

    @Override
    public String getHost() {
        return this.jTextFieldHost.getText();
    }

    @Override
    public int getPort() {
        return Integer.valueOf(this.jTextFieldPort.getText());
    }

    @Override
    public boolean isDebugWaitForDoneSelected() {
        return this.jCheckBoxMenuItemDebugWaitForDone.isSelected();
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JButton jButtonAddProgramItem;
    private javax.swing.JButton jButtonConnect;
    private javax.swing.JButton jButtonDeletProgramItem;
    private javax.swing.JButton jButtonDisconnect;
    private javax.swing.JButton jButtonEditProgramItem;
    private javax.swing.JButton jButtonEnd;
    private javax.swing.JButton jButtonInit;
    private javax.swing.JButton jButtonMoveTo;
    private javax.swing.JButton jButtonMoveToCurrent;
    private javax.swing.JButton jButtonPlotProgramItem;
    private javax.swing.JButton jButtonProgramAbort;
    private javax.swing.JButton jButtonProgramPause;
    private javax.swing.JButton jButtonProgramRun;
    private javax.swing.JButton jButtonResume;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItemDebugReadStatus;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItemDebugSendCommand;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItemDebugWaitForDone;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItemJoints;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItemPlotXYZ;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItemRecordPoseList;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItemReplaceState;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItemUseEXI;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItemUseReadStatusThread;
    private javax.swing.JCheckBoxMenuItem jCheckBoxMenuItemValidateXml;
    private javax.swing.JCheckBox jCheckBoxPoll;
    private javax.swing.JCheckBox jCheckBoxStraight;
    private javax.swing.JComboBox jComboBox1;
    private javax.swing.JComboBox jComboBoxXYZRPY;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel10;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JLabel jLabel5;
    private javax.swing.JLabel jLabel6;
    private javax.swing.JLabel jLabel7;
    private javax.swing.JLabel jLabel8;
    private javax.swing.JLabel jLabel9;
    private javax.swing.JLabel jLabelJogMinus;
    private javax.swing.JLabel jLabelJogMinus1;
    private javax.swing.JLabel jLabelJogPlus;
    private javax.swing.JLabel jLabelJogPlus1;
    private javax.swing.JMenu jMenu1;
    private javax.swing.JMenu jMenu2;
    private javax.swing.JMenuBar jMenuBarReplaceCommandState;
    private javax.swing.JMenu jMenuCmds;
    private javax.swing.JMenu jMenuCommandRecent;
    private javax.swing.JMenuItem jMenuItemExit;
    private javax.swing.JMenuItem jMenuItemOpenStatusLog;
    private javax.swing.JMenuItem jMenuItemOpenXmlCommandInstance;
    private javax.swing.JMenuItem jMenuItemOpenXmlProgram;
    private javax.swing.JMenuItem jMenuItemPoseList3DPlot;
    private javax.swing.JMenuItem jMenuItemRunTest;
    private javax.swing.JMenuItem jMenuItemSavePoseList;
    private javax.swing.JMenuItem jMenuItemSaveProgramAs;
    private javax.swing.JMenuItem jMenuItemSetSchemaFiles;
    private javax.swing.JMenuItem jMenuItemXPathQuery;
    private javax.swing.JMenu jMenuOptions;
    private javax.swing.JMenu jMenuRecentProgram;
    private javax.swing.JMenu jMenuTools;
    private javax.swing.JMenu jMenuXmlSchemas;
    private javax.swing.JPanel jPanel1;
    private javax.swing.JPanel jPanel3;
    private javax.swing.JPanel jPanel5;
    private javax.swing.JPanel jPanel6;
    private javax.swing.JPanel jPanelJogMinus;
    private javax.swing.JPanel jPanelJogMinus1;
    private javax.swing.JPanel jPanelJogPlus;
    private javax.swing.JPanel jPanelJogPlus1;
    private javax.swing.JPanel jPanelJogging;
    private javax.swing.JPanel jPanelMoveTo;
    private javax.swing.JPanel jPanelProgram;
    private javax.swing.JScrollPane jScrollPane1;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane3;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JScrollPane jScrollPaneProgram;
    private javax.swing.JTabbedPane jTabbedPane1;
    private javax.swing.JTable jTableJoints;
    private javax.swing.JTable jTableMoveToPose;
    private javax.swing.JTable jTablePose;
    private javax.swing.JTable jTableProgram;
    private javax.swing.JTextArea jTextAreaErrors;
    private javax.swing.JTextField jTextFieldHost;
    private javax.swing.JTextField jTextFieldJogTime;
    private javax.swing.JTextField jTextFieldJointJogIncrement;
    private javax.swing.JTextField jTextFieldPollTime;
    private javax.swing.JTextField jTextFieldPort;
    private javax.swing.JTextField jTextFieldRPYJogIncrement;
    private javax.swing.JTextField jTextFieldStatCmdID;
    private javax.swing.JTextField jTextFieldStatus;
    private javax.swing.JTextField jTextFieldStatusID;
    private javax.swing.JTextField jTextFieldXYZJogIncrement;
    // End of variables declaration//GEN-END:variables

    @Override
    public boolean isDebugSendCommandSelected() {
        return this.jCheckBoxMenuItemDebugSendCommand.isSelected();
    }

    @Override
    public boolean isDebugReadStatusSelected() {
        return this.jCheckBoxMenuItemDebugReadStatus.isSelected();
    }
    
    

    @Override
    public void showLastProgramLineExecTimeMillisDists(long millis, double dist) {
        DefaultTableModel dtm = (DefaultTableModel) this.jTableProgram.getModel();
        final int row = this.jTableProgram.getSelectedRow();
        if(row >= 0 && row < dtm.getRowCount()) {
            dtm.setValueAt(millis, row, 2);
            dtm.setValueAt(dist, row, 3);
        }
    }
    
    
}
