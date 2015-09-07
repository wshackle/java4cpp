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

import com.siemens.ct.exi.EXIFactory;
import com.siemens.ct.exi.GrammarFactory;
import com.siemens.ct.exi.api.sax.EXIResult;
import com.siemens.ct.exi.api.sax.EXISource;
import com.siemens.ct.exi.exceptions.EXIException;
import com.siemens.ct.exi.grammars.Grammars;
import com.siemens.ct.exi.helpers.DefaultEXIFactory;
import crcl.base.CRCLCommandInstanceType;
import crcl.base.CRCLCommandType;
import crcl.base.CRCLProgramType;
import crcl.base.CRCLStatusType;
import crcl.base.CommandStatusType;
import crcl.base.GetStatusType;
import crcl.base.JointStatusType;
import crcl.base.JointStatusesType;
import crcl.base.ObjectFactory;
import crcl.base.PointType;
import crcl.base.PoseType;
import crcl.base.VectorType;
import java.awt.Component;
import java.io.BufferedInputStream;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileFilter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.io.StringReader;
import java.io.StringWriter;
import java.math.BigInteger;
import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.Socket;
import java.net.SocketException;
import java.nio.ByteBuffer;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import java.util.Random;
import java.util.function.Predicate;
import java.util.function.Supplier;
import java.util.function.UnaryOperator;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import javax.xml.XMLConstants;
import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBElement;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;
import javax.xml.transform.Source;
import javax.xml.transform.sax.SAXSource;
import javax.xml.transform.stream.StreamSource;
import javax.xml.validation.Schema;
import javax.xml.validation.SchemaFactory;
import org.xml.sax.ContentHandler;
import org.xml.sax.InputSource;
import org.xml.sax.SAXException;
import org.xml.sax.XMLReader;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov> }
 */
public class CRCLSocket implements AutoCloseable {

    CRCLSocket() {
        this(null);
    }

    public static final int DEFAULT_PORT = 64444;

    public boolean isConnected() {
        return null != sock && sock.isConnected();

    }

    public int available() {
        try {
            if (sock == null || getBufferedInputStream() == null) {
                return 0;
            }
            if (null != bufferedInputStream) {
                return bufferedInputStream.available();
            }
            return getBufferedInputStream().available();
        } catch (IOException ex) {
//            Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
            return 0;
        }
    }

    private static String addCRCLToStatePriv(String in) {
        return in.replaceAll("<CommandState>Working</CommandState>", "<CommandState>CRCL_Working</CommandState>")
                .replaceAll("<CommandState>Done</CommandState>", "<CommandState>CRCL_Done</CommandState>")
                .replaceAll("<CommandState>Error</CommandState>", "<CommandState>CRCL_Error</CommandState>")
                .replaceAll("<CommandState>Ready</CommandState>", "<CommandState>CRCL_Ready</CommandState>");
    }

    static final public UnaryOperator<String> addCRCLToState = new UnaryOperator<String>() {

        @Override
        public String apply(String t) {
            return addCRCLToStatePriv(t);
        }
    };

    private static String removeCRCLFromStatePriv(String in) {
        return in.replaceAll("<CommandState>CRCL_Working</CommandState>", "<CommandState>Working</CommandState>")
                .replaceAll("<CommandState>CRCL_Done</CommandState>", "<CommandState>Done</CommandState>")
                .replaceAll("<CommandState>CRCL_Error</CommandState>", "<CommandState>Error</CommandState>")
                .replaceAll("<CommandState>CRCL_Ready</CommandState>", "<CommandState>Ready</CommandState>");
    }

    static final public UnaryOperator<String> removeCRCLFromState = new UnaryOperator<String>() {

        @Override
        public String apply(String t) {
            return removeCRCLFromStatePriv(t);
        }
    };

    private UnaryOperator<String> statusStringInputFilter = null;

    public int getLocalPort() {
        if (null == this.sock) {
            return -1;
        }
        return this.sock.getLocalPort();
    }

    public int getPort() {
        if (null == this.sock) {
            return -1;
        }
        return this.sock.getPort();
    }

    public InetAddress getInetAddress() {
        if (null == this.sock) {
            return null;
        }
        return this.sock.getInetAddress();
    }

    /**
     * Get the value of statusStringInputFilter
     *
     * @return the value of statusStringInputFilter
     */
    public UnaryOperator<String> getStatusStringInputFilter() {
        return statusStringInputFilter;
    }

    /**
     * Set the value of statusStringInputFilter
     *
     * @param statusStringInputFilter new value of statusStringInputFilter
     */
    public void setStatusStringInputFilter(UnaryOperator<String> statusStringInputFilter) {
        this.statusStringInputFilter = statusStringInputFilter;
    }

    private UnaryOperator<String> statusStringOutputFilter = null;

    /**
     * Get the value of statusStringOutputFilter
     *
     * @return the value of statusStringOutputFilter
     */
    public UnaryOperator<String> getStatusStringOutputFilter() {
        return statusStringOutputFilter;
    }

    /**
     * Set the value of statusStringOutputFilter
     *
     * @param statusStringOutputFilter new value of statusStringOutputFilter
     */
    public void setStatusStringOutputFilter(UnaryOperator<String> statusStringOutputFilter) {
        this.statusStringOutputFilter = statusStringOutputFilter;
    }

    public static String statusHeader = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
            + "<CRCLStatus\n"
            + "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            + "  xsi:noNamespaceSchemaLocation=\"../xmlSchemas/CRCLStatus.xsd\">";

    public static String cmdHeader = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
            + "<CRCLCommandInstance\n"
            + "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            + "  xsi:noNamespaceSchemaLocation=\"../xmlSchemas/CRCLCommandInstance.xsd\">";

    public static String progHeader = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"
            + "<CRCLProgram\n"
            + "  xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\"\n"
            + "  xsi:noNamespaceSchemaLocation=\"../xmlSchemas/CRCLProgramInstance.xsd\">";

    public static boolean DEFAULT_JAXB_FRAGMENT = true;

//    public static String DEFAULT_XML_HEADER_OVERRIDE
//            = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>";
//    private String xmlHeader = DEFAULT_XML_HEADER_OVERRIDE;
    private boolean jaxbFragment = DEFAULT_JAXB_FRAGMENT;

//    public static String DEFAULT_STATUS_NO_NAMESPACE_JAXB_SCHEMA_LOCATION = "../xmlSchemas/CRCLStatus.xsd";
//    public static String DEFAULT_COMMAND_NO_NAMESPACE_JAXB_SCHEMA_LOCATION = ".../xmlSchemas/CRCLCommandInstance.xsd";
//    public static String DEFAULT_PROGRAM_NO_NAMESPACE_JAXB_SCHEMA_LOCATION = "../xmlSchemas/CRCLProgramInstance.xsd";
//    public static String DEFAULT_JAXB_SCHEMA_LOCATION = "http://www.w3.org/2001/XMLSchema-instance";
    /**
     * Get the value of jaxbFragment
     *
     * @return the value of jaxbFragment
     */
    public boolean isJaxbFragment() {
        return jaxbFragment;
    }

    /**
     * Set the value of jaxbFragment
     *
     * @param jaxbFragment new value of jaxbFragment
     */
    public void setJaxbFragment(boolean jaxbFragment) {
        this.jaxbFragment = jaxbFragment;
    }

    private final Socket sock;

    private String lastStatusString;

    /**
     * Get the value of lastStatusString
     *
     * @return the value of lastStatusString
     */
    public String getLastStatusString() {
        return lastStatusString;
    }

    private String lastCommandString;
    private String lastProgramString;

    /**
     * Get the value of lastCommandString
     *
     * @return the value of lastCommandString
     */
    public synchronized String getLastCommandString() {
        return lastCommandString;
    }

    public static Schema defaultCmdSchema = null;
    public static Schema defaultProgramSchema = null;
    public static Schema defaultStatSchema = null;

    public static File commandXsdFile = null;

    private Schema cmdSchema = defaultCmdSchema;
    private Schema programSchema = defaultProgramSchema;

    /**
     * Get the value of cmdSchema
     *
     * @return the value of cmdSchema
     */
    public Schema getProgramSchema() {
        return programSchema;
    }

    /**
     * Set the value of cmdSchema
     *
     * @param programSchema new value of cmdSchema
     */
    public void setProgramSchema(Schema programSchema) {
        this.programSchema = programSchema;
        this.m_prog.setSchema(programSchema);
        this.u_prog.setSchema(programSchema);
    }

    /**
     * Get the value of cmdSchema
     *
     * @return the value of cmdSchema
     */
    public Schema getCmdSchema() {
        return cmdSchema;
    }

    /**
     * Set the value of cmdSchema
     *
     * @param cmdSchema new value of cmdSchema
     */
    public void setCmdSchema(Schema cmdSchema) {
        this.cmdSchema = cmdSchema;
        m_cmd.setSchema(cmdSchema);
        u_cmd.setSchema(cmdSchema);
    }

    private Schema statSchema = defaultStatSchema;

    /**
     * Get the value of statSchema
     *
     * @return the value of statSchema
     */
    public Schema getStatSchema() {
        return statSchema;
    }

    /**
     * Set the value of statSchema
     *
     * @param statSchema new value of statSchema
     */
    public void setStatSchema(Schema statSchema) {
        this.statSchema = statSchema;
        m_stat.setSchema(statSchema);
        u_stat.setSchema(statSchema);
    }

    public CRCLSocket(Socket sock) {
        Marshaller tmp_m_cmd = null;
        Unmarshaller tmp_u_cmd = null;
        Marshaller tmp_m_stat = null;
        Unmarshaller tmp_u_stat = null;
        Marshaller tmp_m_prog = null;
        Unmarshaller tmp_u_prog = null;
        try {
            Supplier<JAXBContext> jc = () -> {
                try {
                    JAXBContext jc2 = JAXBContext.newInstance("crcl.base");
                    return jc2;
                } catch (JAXBException ex) {
                    LOGGER.log(Level.SEVERE, null, ex);
                }
                return null;
            };
            tmp_u_cmd = jc.get().createUnmarshaller();
            tmp_m_cmd = jc.get().createMarshaller();
//            tmp_m_cmd.setProperty(Marshaller.JAXB_FRAGMENT, jaxbFragment);
//            tmp_m_cmd.setProperty(Marshaller.JAXB_NO_NAMESPACE_SCHEMA_LOCATION, DEFAULT_COMMAND_NO_NAMESPACE_JAXB_SCHEMA_LOCATION);
//            tmp_m_cmd.setProperty(Marshaller.JAXB_SCHEMA_LOCATION, DEFAULT_JAXB_SCHEMA_LOCATION);
            if (null != defaultCmdSchema) {
                tmp_u_cmd.setSchema(defaultCmdSchema);
                tmp_m_cmd.setSchema(defaultCmdSchema);
            }
            tmp_u_stat = jc.get().createUnmarshaller();
            tmp_m_stat = jc.get().createMarshaller();
//            tmp_m_stat.setProperty(Marshaller.JAXB_FRAGMENT, jaxbFragment);
//            tmp_m_stat.setProperty(Marshaller.JAXB_NO_NAMESPACE_SCHEMA_LOCATION, DEFAULT_STATUS_NO_NAMESPACE_JAXB_SCHEMA_LOCATION);
//            tmp_m_stat.setProperty(Marshaller.JAXB_SCHEMA_LOCATION, DEFAULT_JAXB_SCHEMA_LOCATION);
            if (null != defaultStatSchema) {
                tmp_u_stat.setSchema(defaultStatSchema);
                tmp_m_stat.setSchema(defaultStatSchema);
            }
            tmp_u_prog = jc.get().createUnmarshaller();
            tmp_m_prog = jc.get().createMarshaller();
//            tmp_m_prog.setProperty(Marshaller.JAXB_FRAGMENT, jaxbFragment);
//            tmp_m_prog.setProperty(Marshaller.JAXB_NO_NAMESPACE_SCHEMA_LOCATION, DEFAULT_PROGRAM_NO_NAMESPACE_JAXB_SCHEMA_LOCATION);
//            tmp_m_prog.setProperty(Marshaller.JAXB_SCHEMA_LOCATION, DEFAULT_JAXB_SCHEMA_LOCATION);
            if (null != defaultProgramSchema) {
                tmp_u_prog.setSchema(defaultProgramSchema);
                tmp_m_prog.setSchema(defaultProgramSchema);
            }
        } catch (JAXBException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
        m_cmd = tmp_m_cmd;
        u_cmd = tmp_u_cmd;
        m_stat = tmp_m_stat;
        u_stat = tmp_u_stat;
        m_prog = tmp_m_prog;
        u_prog = tmp_u_prog;
        this.sock = sock;
    }
    private static final Logger LOGGER = Logger.getLogger(CRCLSocket.class.getName());

    public CRCLSocket(String hostname, int port) throws IOException {
        this(new Socket(hostname, port));
    }

    @Override
    public synchronized void close() throws IOException {
        sock.close();
        exiCommandInSaxSource = null;
        if (null != bufferedInputStream) {
            try {
                bufferedInputStream.close();
            } catch (Exception e) {
            }
            bufferedInputStream = null;
        }
    }

    @Override
    protected void finalize() throws Throwable {
        super.finalize();
        this.close();
    }

    private final Marshaller m_cmd;
    private final Unmarshaller u_cmd;

    private final Marshaller m_prog;
    private final Unmarshaller u_prog;

    private final Marshaller m_stat;
    private final Unmarshaller u_stat;

    static JointStatusType getJointStatus(CRCLStatusType _status, int i) {
        BigInteger bi = BigInteger.valueOf(i);
        return getJointStatus(_status, bi);
    }

    static JointStatusType getJointStatus(CRCLStatusType _status, BigInteger bi) {
        if (null == _status) {
            return null;
        }
        JointStatusesType jsst = _status.getJointStatuses();
        if (null == jsst) {
            return null;
        }
        List<JointStatusType> jsl = jsst.getJointStatus();
        for (JointStatusType js : jsl) {
            if (js.getJointNumber().equals(bi)) {
                return js;
            }
        }
        return null;
    }

    private String readInProgressString = "";

    public String getReadInProgressString() {
        return this.readInProgressString;
    }

    public String readUntilEndTag(final String tag, final InputStream is) throws IOException {
        byte ba1[] = new byte[1];
        String rips = "";
        final String endTagStartString = "</" + tag;
        final String startTag = "<" + tag;
        boolean insideStartTag = false;
        boolean startTag_found = false;
        boolean endTag_started = false;
        String str = "";
        String skipped_str = "";
        StringBuilder sb = new StringBuilder();
        synchronized (is) {
            while (ba1[0] != '>' || !endTag_started) {
                int bytes_read = is.read(ba1);
                if (bytes_read != 1) {
                    Level lvl = rips.length() > 0 ? Level.SEVERE : Level.FINE;
                    final int brF = bytes_read;
                    final String ripsF = rips;
                    LOGGER.log(lvl,
                            () -> "CRCLSocket.readUntilEndTag(" + tag + "): read returned " + brF + " before end of tag was found. str = " + ripsF);
                    throw new SocketException("socket closed after read returned:" + bytes_read);
                }
                if (ba1[0] == 0) {
                    continue;
                }
                rips += new String(ba1);
                if (ba1[0] == '>' && !endTag_started && insideStartTag) {
                    if (rips.endsWith("/>")) {
                        break;
                    }
                    insideStartTag = false;
                }
                this.readInProgressString = rips;
                if (!startTag_found) {
                    while (rips.length() > 0
                            && !rips.startsWith(startTag.substring(0, Math.min(rips.length(), startTag.length())))) {
                        skipped_str += rips.substring(0, 1);
                        rips = rips.substring(1);
                        this.readInProgressString = rips;
                    }
                    if (rips.startsWith(startTag)) {
                        startTag_found = true;
                        insideStartTag = true;
                    }
                } else if (!endTag_started) {
                    endTag_started = rips.endsWith(endTagStartString);
                }
            }
            str = rips;
            rips = "";
            this.readInProgressString = rips;
        }
        final String threadName = Thread.currentThread().getName();
        final String skipped_str_f = skipped_str;
        LOGGER.log(Level.FINER,
                () -> "readUntilEndTag(" + tag + ") called with skipped_str=\"" + skipped_str_f + "\"  from Thread: " + threadName);
        return str;
    }

    public CRCLCommandInstanceType stringToCommand(String str, boolean validate) throws JAXBException {
        synchronized (u_cmd) {
            this.lastCommandString = str;
            u_cmd.setSchema(validate ? cmdSchema : null);
            JAXBElement el = (JAXBElement) u_cmd.unmarshal(new StringReader(str));
            CRCLCommandInstanceType instance
                    = (CRCLCommandInstanceType) el.getValue();
            return instance;
        }
    }

    public CRCLCommandInstanceType readCommandFromStream(final InputStream is, boolean validate) throws JAXBException {
        synchronized (u_cmd) {
//            this.lastCommandString = str;
            u_cmd.setSchema(validate ? cmdSchema : null);
            JAXBElement el = (JAXBElement) u_cmd.unmarshal(is);
            CRCLCommandInstanceType instance
                    = (CRCLCommandInstanceType) el.getValue();
            return instance;
        }
    }

    public CRCLProgramType stringToProgram(String str, boolean validate) throws JAXBException {
        synchronized (u_prog) {
            this.lastProgramString = str;
            u_prog.setSchema(validate ? programSchema : null);
            JAXBElement el = (JAXBElement) u_prog.unmarshal(new StringReader(str));
            CRCLProgramType prog
                    = (CRCLProgramType) el.getValue();
            return prog;
        }
    }

    public synchronized CRCLCommandInstanceType readCommand(boolean validate) throws JAXBException, IOException, EXIException {
        final String threadName = Thread.currentThread().getName();
        final boolean EXI = this.isEXIEnabled();
//        LOGGER.log(Level.FINE,
//                ()-> "readCommand() called with EXI = " + EXI+ " from Thread: "+ threadName);
        if (this.isEXIEnabled()) {
            if (!this.isPrefixEXISizeEnabled()) {
                final CRCLCommandInstanceType c = this.readCommandFromEXIStream(getBufferedInputStream());
                final CRCLCommandType cc = c.getCRCLCommand();
                final Level loglevel = (cc instanceof GetStatusType) ? Level.FINER : Level.FINE;
                LOGGER.log(loglevel,
                        () -> "readCommand() returning " + cc + " ID=" + cc.getCommandID() + " called from Thread: " + threadName);
                return c;
            } else {
                byte sizeba[] = new byte[4];
                int r1 = getBufferedInputStream().read(sizeba);
//                LOGGER.log(Level.FINEST,() ->"readCommand: r1 = " + r1);
//                LOGGER.log(Level.FINEST,() ->"readCommand: sizeba = " + Arrays.toString(sizeba));
                ByteBuffer bb = ByteBuffer.wrap(sizeba);
                int size = bb.getInt();
//                LOGGER.log(Level.FINEST,() ->"readCommand: size = " + size);
                byte ba[] = new byte[size];
                int r2 = getBufferedInputStream().read(ba);
//                LOGGER.log(Level.FINEST,() ->"readCommand: r2 = " + r2);
//                LOGGER.log(Level.FINEST,() ->"readCommand: ba.length = " + ba.length);
//                LOGGER.log(Level.FINEST,() ->"readCommand: ba = " + Arrays.toString(ba));
                final CRCLCommandInstanceType c = exiToCommand(ba);
                final CRCLCommandType cc = c.getCRCLCommand();
                final Level loglevel = (cc instanceof GetStatusType) ? Level.FINER : Level.FINE;
                LOGGER.log(loglevel,
                        () -> "readCommand() returning " + cc
                        + " ID=" + cc.getCommandID()
                        + " called from Thread: " + threadName);
                return c;
            }
        }
//        return readCommandFromStream(getBufferedInputStream(), validate);
        final String str = this.readUntilEndTag("CRCLCommandInstance", getBufferedInputStream());
        if (null == str) {
            return null;
        }
        CRCLCommandInstanceType cmd = stringToCommand(str, validate);
        final CRCLCommandType cc = cmd.getCRCLCommand();
        final Level loglevel = (cc instanceof GetStatusType) ? Level.FINER : Level.FINE;
        LOGGER.log(loglevel,
                () -> "readCommand() returning " + cc + " ID=" + cc.getCommandID() + "str=" + str + "  called from Thread: " + threadName);
        this.lastCommandString = str;
        return cmd;
    }

    public CRCLStatusType stringToStatus(String str, boolean validate) throws JAXBException {
        synchronized (u_stat) {
            if (this.statusStringInputFilter != null) {
                str = this.statusStringInputFilter.apply(str);
            }
            lastStatusString = str;
            u_stat.setSchema(validate ? statSchema : null);
            JAXBElement el = (JAXBElement) u_stat.unmarshal(new StringReader(str));
            CRCLStatusType instance
                    = (CRCLStatusType) el.getValue();
            return instance;
        }
    }

    public CRCLStatusType readStatusFromStream(final InputStream is, boolean validate) throws JAXBException {
        synchronized (u_stat) {
//            if (this.statusStringInputFilter != null) {
//                str = this.statusStringInputFilter.apply(str);
//            }
//            lastStatusString = str;
            u_stat.setSchema(validate ? statSchema : null);
            JAXBElement el = (JAXBElement) u_stat.unmarshal(is);
            CRCLStatusType instance
                    = (CRCLStatusType) el.getValue();
            return instance;
        }
    }

    private boolean EXIEnabled = Boolean.valueOf(System.getProperty("crcl.EXIEnabled", "false"));

    /**
     * Get the value of EXIEnabled
     *
     * @return the value of EXIEnabled
     */
    public boolean isEXIEnabled() {
        return EXIEnabled;
    }

    private boolean prefixEXISizeEnabled = Boolean.valueOf(System.getProperty("crcl.prefixEXISizeEnabled", "false"));

    /**
     * Get the value of prefixEXISizeEnabled
     *
     * @return the value of prefixEXISizeEnabled
     */
    public boolean isPrefixEXISizeEnabled() {
        return prefixEXISizeEnabled;
    }

    /**
     * Set the value of prefixEXISizeEnabled
     *
     * @param prefixEXISizeEnabled new value of prefixEXISizeEnabled
     */
    public void setPrefixEXISizeEnabled(boolean prefixEXISizeEnabled) {
        this.prefixEXISizeEnabled = prefixEXISizeEnabled;
    }

    private EXIFactory exiStatusFactory = null;

    private EXIFactory getExiStatusFactory() throws EXIException, IOException {
        if (null != exiStatusFactory) {
            return exiStatusFactory;
        }
        copySchemaResources();
        exiStatusFactory = DefaultEXIFactory.newInstance();
        GrammarFactory grammarFactory = GrammarFactory.newInstance();
        Grammars g = grammarFactory.createGrammars(crclSchemaDirFile.getCanonicalPath() + File.separator + "CRCLStatus.xsd");
        exiStatusFactory.setGrammars(g);
        return exiStatusFactory;
    }

    private EXIFactory exiCommandFactory = null;

    private EXIFactory getExiCommandFactory() throws EXIException, IOException {
        if (null != exiCommandFactory) {
            return exiCommandFactory;
        }
        copySchemaResources();
        exiCommandFactory = DefaultEXIFactory.newInstance();
        GrammarFactory grammarFactory = GrammarFactory.newInstance();
        Grammars g = grammarFactory.createGrammars(crclSchemaDirFile.getCanonicalPath() + File.separator + "CRCLCommandInstance.xsd");
        exiCommandFactory.setGrammars(g);
        return exiCommandFactory;
    }

    /**
     * Set the value of EXIEnabled
     *
     * @param EXIEnabled new value of EXIEnabled
     * @throws com.siemens.ct.exi.exceptions.EXIException internal EXI lib fault
     */
    public void setEXIEnabled(boolean EXIEnabled) throws EXIException {
        this.EXIEnabled = EXIEnabled;
        if (!EXIEnabled) {
            exiStatusFactory = null;
            exiCommandFactory = null;
        }
    }

//    protected void encode(ContentHandler ch) throws SAXException, IOException {
//        XMLReader xmlReader = XMLReaderFactory.createXMLReader();
//        xmlReader.setContentHandler(ch);
//
//        // parse xml file
//        xmlReader.parse(new InputSource(xmlLocation));
//    }
//
//    protected void decode(XMLReader exiReader, String exiLocation)
//            throws SAXException, IOException, TransformerException {
//
//        TransformerFactory tf = TransformerFactory.newInstance();
//        Transformer transformer = tf.newTransformer();
//
//        InputStream exiIS = new FileInputStream(exiLocation);
//        SAXSource exiSource = new SAXSource(new InputSource(exiIS));
//        exiSource.setXMLReader(exiReader);
//
//        OutputStream os = new FileOutputStream(exiLocation + XML_EXTENSION);
//        transformer.transform(exiSource, new StreamResult(os));
//        os.close();
//    }
    public byte[] statusToEXI(CRCLStatusType status) throws JAXBException, IOException, EXIException {
        final String threadName = Thread.currentThread().getName();
        try (ByteArrayOutputStream exiOS = new ByteArrayOutputStream()) {
            writeEXIStatusToStream(exiOS, status);
            return exiOS.toByteArray();
        } catch (Exception ex) {
            final String xmlS = this.statusToString(status, true);
            LOGGER.log(Level.SEVERE,
                    "CRCLStatus.statusToEXIFirst() Exception Thread=" + threadName + ", status=" + statToDebugString(status) + ",xmlS=" + xmlS,
                    ex);
            final Level origLevel = LOGGER.getLevel();
            final Logger xmlInternalLogger = Logger.getLogger("com.sun.xml.internal.bind");
            final Level origXmlInternalLogLevel = xmlInternalLogger.getLevel();
            try (ByteArrayOutputStream exiOS = new ByteArrayOutputStream()) {
                writeEXIStatusToStream(exiOS, status);
                final byte ba[] = exiOS.toByteArray();
                LOGGER.log(Level.SEVERE,
                        "writeEXIStatusTOStream succeeded on second try. ba=" + ba);
                return ba;
            } finally {
                xmlInternalLogger.setLevel(origXmlInternalLogLevel);
                LOGGER.setLevel(origLevel);
            }
        }
    }

    public byte[] commandToEXI(CRCLCommandInstanceType cmd) throws JAXBException, IOException, EXIException {
        try (ByteArrayOutputStream exiOS = new ByteArrayOutputStream()) {
            writeEXICommandToStream(exiOS, cmd);
            return exiOS.toByteArray();
        }
    }

    private static String vectorToDebugString(final VectorType v) {
        return v == null ? "null" : v.toString() + " { "
                + "I=" + v.getI() + ","
                + "J=" + v.getJ() + ","
                + "K=" + v.getK() + " } ";
    }

    private static String pointToDebugString(final PointType p) {
        return p == null ? "null" : p.toString() + " { "
                + "X=" + p.getX() + ","
                + "Y=" + p.getY() + ","
                + "Z=" + p.getZ() + " } ";
    }

    private static String poseToDebugString(final PoseType p) {
        return p == null ? "null" : p.toString() + " { "
                + "Point=" + pointToDebugString(p.getPoint()) + ","
                + "XAxis=" + vectorToDebugString(p.getXAxis()) + ","
                + "ZAxis=" + vectorToDebugString(p.getZAxis()) + " } ";
    }

    private static String commandStatToDebugString(final CommandStatusType c) {
        return c == null ? "null" : c.toString() + " { "
                + "CommandId=" + c.getCommandID() + ","
                + "CommandState=" + c.getCommandState() + ","
                + "StatusId=" + c.getStatusID() + " } ";
    }

    private static String jointStatusToDebugString(final JointStatusType j) {
        return j == null ? "null" : j.toString() + " { "
                + "JointNumber=" + j.getJointNumber() + ","
                + "Position=" + j.getJointPosition() + ","
                + "Velocity=" + j.getJointVelocity() + ","
                + "TorqueOrForce=" + j.getJointTorqueOrForce()
                + " } ";
    }

    private static String jointStatusListToDebugString(final List<JointStatusType> l) {
        return l == null ? "null" : l.toString() + " { "
                + l.stream()
                .map(CRCLSocket::jointStatusToDebugString)
                .collect(Collectors.joining(",")) + " } ";
    }

    private static String jointStatusesToDebugString(final JointStatusesType j) {
        return j == null ? "null" : j.toString() + " { "
                + "JointStatus=" + jointStatusListToDebugString(j.getJointStatus()) + " } ";
    }

    public static String statToDebugString(final CRCLStatusType stat) {
        return stat == null ? "null" : stat.toString() + " { "
                + "CommandStatus=" + commandStatToDebugString(stat.getCommandStatus()) + ","
                + "Pose=" + poseToDebugString(stat.getPose()) + ","
                + "JointStatuses=" + jointStatusesToDebugString(stat.getJointStatuses()) + " } ";
    }

    /**
     *
     * @param outStream the value of outStream
     * @param status status to write
     * @throws IOException network failure
     * @throws JAXBException JAXB failure
     * @throws EXIException EXI lib failure
     */
    public void writeEXIStatusToStream(
            final java.io.OutputStream outStream,
            CRCLStatusType status)
            throws IOException, JAXBException, EXIException {
        final EXIResult exiResult = new EXIResult(getExiStatusFactory());
        exiResult.setOutputStream(outStream);
        final ContentHandler handler = exiResult.getHandler();
        JAXBElement<CRCLStatusType> jaxb_status
                = objectFactory.createCRCLStatus(status);
        final String threadName = Thread.currentThread().getName();
        synchronized (m_stat) {
//            try {
            m_stat.marshal(jaxb_status, handler);
//            } catch (Throwable t) {
//                LOGGER.log(Level.SEVERE,
//                        "First Exception Thread=" + threadName + ", jaxb_status=" + jaxb_status + ", status=" + statToDebugString(status),
//                        t);
//                final Level origLevel = LOGGER.getLevel();
//                final Logger xmlInternalLogger = Logger.getLogger("com.sun.xml.internal.bind");
//                final Level origXmlInternalLogLevel = xmlInternalLogger.getLevel();
//                try {
//                    final EXIResult exiResultNew = new EXIResult(getExiStatusFactory());
//                    exiResultNew.setOutputStream(outStream);
//                    final ContentHandler handlerNew = exiResultNew.getHandler();
//                    JAXBElement<CRCLStatusType> jaxb_statusNew
//                            = objectFactory.createCRCLStatus(status);
//                    xmlInternalLogger.setLevel(Level.ALL);
//                    LOGGER.setLevel(Level.ALL);
//                    m_stat.marshal(jaxb_statusNew, handlerNew);
//                    LOGGER.log(Level.SEVERE, "Data marshalled on second attempt.");
//                } catch (Exception ex2) {
//                    LOGGER.log(Level.SEVERE,
//                            "Second Exception Thread=" + threadName,
//                            ex2);
//                } finally {
//                    LOGGER.setLevel(origLevel);
//                    xmlInternalLogger.setLevel(origXmlInternalLogLevel);
//                }
//            }
        }
    }

    /**
     * Write an EXI Command to a stream
     *
     * @param outStream the value of outStream
     * @param cmdInstance command to send
     * @throws IOException network failure
     * @throws JAXBException JAXB failure
     * @throws EXIException EXI lib failure
     */
    public void writeEXICommandToStream(
            final java.io.OutputStream outStream,
            CRCLCommandInstanceType cmdInstance)
            throws IOException, JAXBException, EXIException {
        final EXIResult exiResult = new EXIResult(getExiCommandFactory());
        outStream.flush();
        exiResult.setOutputStream(outStream);
        final ContentHandler handler = exiResult.getHandler();
        JAXBElement<CRCLCommandInstanceType> jaxb_cmd_instance
                = objectFactory.createCRCLCommandInstance(cmdInstance);
        final String threadName = Thread.currentThread().getName();
        synchronized (m_cmd) {
            try {
                m_cmd.marshal(jaxb_cmd_instance, handler);
                outStream.flush();
            } catch (NullPointerException nullPointerException) {
                LOGGER.log(Level.SEVERE,
                        "First NPE Thread=" + threadName, nullPointerException);
                try {
                    m_cmd.marshal(jaxb_cmd_instance, handler);
                } catch (NullPointerException nullPointerException2) {
                    LOGGER.log(Level.SEVERE,
                            "Second NPE Thread=" + threadName,
                            nullPointerException);
                }
            }
        }
    }

    public CRCLStatusType exiToStatus(byte exi[]) throws EXIException, JAXBException, IOException {
        try (final InputStream inputStream = new ByteArrayInputStream(exi)) {
            return readStatusFromEXIStream(inputStream);
        }
    }

    public CRCLCommandInstanceType exiToCommand(byte exi[])
            throws EXIException, JAXBException, IOException {
        try (final InputStream inputStream = new ByteArrayInputStream(exi)) {
            return readCommandFromEXIStream(inputStream);
        }
    }

//    private SAXSource getStatusSAXSource() throws IOException, EXIException {
//        if(null != statusSAXSource) {
//           return statusSAXSource;
//        }
//        EXISource exiSource = new EXISource(getExiStatusFactory());
//        XMLReader xmlReader = exiSource.getXMLReader();
//        InputSource inputSource = new InputSource(getBufferedInputStream());
//        statusSAXSource = new SAXSource(xmlReader, new InputSource(getBufferedInputStream()));
//        return statusSAXSource;
//    }
    public CRCLStatusType readStatusFromEXIStream(final InputStream inputStream)
            throws EXIException, JAXBException, IOException {
//        EXISource exiSource = new EXISource(getExiStatusFactory());
//        XMLReader xmlReader = exiSource.getXMLReader();
        synchronized (inputStream) {
            return readStatusFromSaxSource(getExiStatusInSaxSource(inputStream));
        }
    }

    public CRCLStatusType readStatusFromSaxSource(SAXSource saxSource) throws JAXBException {
        synchronized (u_stat) {
            JAXBElement<CRCLStatusType> el
                    = u_stat.unmarshal(saxSource, CRCLStatusType.class);
            return el.getValue();
        }
    }

    private BufferedInputStream bufferedInputStream;

    private BufferedInputStream getBufferedInputStream() {
        if (null != bufferedInputStream) {
            return bufferedInputStream;
        }
        if (null != sock) {
            try {
                bufferedInputStream = new BufferedInputStream(sock.getInputStream());
            } catch (IOException ex) {
                Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
            }
        }
        return bufferedInputStream;
    }

    private SAXSource exiCommandInSaxSource = null;

    private SAXSource getExiCommandInSaxSource(final InputStream is) throws EXIException, IOException {

        if (null != exiCommandInSaxSource && exiCommandInSaxSource.getInputSource().getByteStream() == is) {
            return exiCommandInSaxSource;
        }
        EXISource exiSource = new EXISource(getExiCommandFactory());
        XMLReader xmlReader = exiSource.getXMLReader();
//        byte notused_ba[] = new byte[1];
//        InputStream proxyInputStream = new ByteArrayInputStream(notused_ba) {
//
//            int count = 0;
//
//            @Override
//            public int read() {
//                int ret = -1;
//                try {
//                    ret = inputStream.read();
//                    count++;
//                    byte b = (byte) ret;
//                    if (b > 127) {
//                        b -= 256;
//                    }
//                    final int retf = ret;
//                    final byte bf = b;
//                    LOGGER.log(Level.FINEST, () -> "read() returning : " + retf + ", count =" + count + ", b = " + bf);
//                    return ret;
//                } catch (IOException ex) {
//                    Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
//                }
//                return ret;
//            }
//
//            @Override
//            public boolean markSupported() {
//                boolean ret = inputStream.markSupported();
//                LOGGER.log(Level.FINEST, () -> "markSupported() returning " + ret);
//                return ret;
//            }
//
//            @Override
//            public synchronized void reset() {
//                try {
//                    LOGGER.log(Level.FINEST, () -> "reset() called.");
//                    inputStream.reset();
//                } catch (IOException ex) {
//                    Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
//                }
//            }
//
//            @Override
//            public synchronized void mark(int readlimit) {
//                LOGGER.log(Level.FINEST, () -> "mart(" + readlimit + ") called");
//                inputStream.mark(readlimit);
//            }
//
//            @Override
//            public void close() throws IOException {
//                LOGGER.log(Level.FINEST, () -> "close() called");
//                inputStream.close();
//            }
//
//            @Override
//            public int available() {
//                int ret = -1;
//                try {
//                    ret = inputStream.available();
//                    final int retf = ret;
//                    LOGGER.log(Level.FINEST, () -> "available() returning " + retf);
//                } catch (IOException ex) {
//                    Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
//                }
//                return ret;
//            }
//
//            @Override
//            public long skip(long n) {
//                long ret = -1;
//                try {
//                    ret = inputStream.skip(n);
//                    final long retf =ret;
//                    LOGGER.log(Level.FINEST, () -> "skip(" + n + ") returning " + retf);
//                } catch (IOException ex) {
//                    Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
//                }
//                return ret;
//            }
//
//            @Override
//            public int read(byte[] b, int off, int len) {
//                LOGGER.log(Level.FINEST, () -> "read(...," + off + "," + len + ") called.");
//                int ret = -1;
//                try {
//                    ret = inputStream.read(b, off, len);
//                } catch (IOException ex) {
//                    Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
//                }
//                final int retf = ret;
//                if (ret > 0) {
//                    final byte bf[] = b;
//                    LOGGER.log(Level.FINEST, () -> "b = " + Arrays.toString(Arrays.copyOf(bf, retf)));
//                }
//                LOGGER.log(Level.FINEST, () -> "read(...," + off + "," + len + ") returning " + retf);
//                return ret;
//            }
//
//            @Override
//            public int read(byte[] b) throws IOException {
//                LOGGER.log(Level.FINEST, () -> "read(...,) called.");
//                int ret = inputStream.read(b);
//                final int retf = ret;
//                if (ret > 0) {
//                    final byte bf[] = b;
//                    LOGGER.log(Level.FINEST, () -> "b = " + Arrays.toString(Arrays.copyOf(bf, retf)));
//                }
//                
//                LOGGER.log(Level.FINEST, () -> "read(...) returning " + retf);
//                return ret;
//            }
//        };
        exiCommandInSaxSource = new SAXSource(xmlReader, new InputSource(is));
        return exiCommandInSaxSource;
    }

    private SAXSource exiStatusInSaxSource = null;

    private SAXSource getExiStatusInSaxSource(final InputStream is) throws EXIException, IOException {

        if (null != exiStatusInSaxSource && exiStatusInSaxSource.getInputSource().getByteStream() == is) {
            return exiStatusInSaxSource;
        }
        EXISource exiSource = new EXISource(getExiStatusFactory());
        XMLReader xmlReader = exiSource.getXMLReader();
//        byte notused_ba[] = new byte[1];
//        InputStream proxyInputStream = new ByteArrayInputStream(notused_ba) {
//
//            int count = 0;
//
//            @Override
//            public int read() {
//                int ret = -1;
//                try {
//                    ret = inputStream.read();
//                    count++;
//                    byte b = (byte) ret;
//                    if (b > 127) {
//                        b -= 256;
//                    }
//                    final int retf = ret;
//                    final byte bf = b;
//                    LOGGER.log(Level.FINEST, () -> "read() returning : " + retf + ", count =" + count + ", b = " + bf);
//                    return ret;
//                } catch (IOException ex) {
//                    Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
//                }
//                return ret;
//            }
//
//            @Override
//            public boolean markSupported() {
//                boolean ret = inputStream.markSupported();
//                LOGGER.log(Level.FINEST, () -> "markSupported() returning " + ret);
//                return ret;
//            }
//
//            @Override
//            public synchronized void reset() {
//                try {
//                    LOGGER.log(Level.FINEST, () -> "reset() called.");
//                    inputStream.reset();
//                } catch (IOException ex) {
//                    Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
//                }
//            }
//
//            @Override
//            public synchronized void mark(int readlimit) {
//                LOGGER.log(Level.FINEST, () -> "mart(" + readlimit + ") called");
//                inputStream.mark(readlimit);
//            }
//
//            @Override
//            public void close() throws IOException {
//                LOGGER.log(Level.FINEST, () -> "close() called");
//                inputStream.close();
//            }
//
//            @Override
//            public int available() {
//                int ret = -1;
//                try {
//                    ret = inputStream.available();
//                    final int retf = ret;
//                    LOGGER.log(Level.FINEST, () -> "available() returning " + retf);
//                } catch (IOException ex) {
//                    Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
//                }
//                return ret;
//            }
//
//            @Override
//            public long skip(long n) {
//                long ret = -1;
//                try {
//                    ret = inputStream.skip(n);
//                    final long retf =ret;
//                    LOGGER.log(Level.FINEST, () -> "skip(" + n + ") returning " + retf);
//                } catch (IOException ex) {
//                    Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
//                }
//                return ret;
//            }
//
//            @Override
//            public int read(byte[] b, int off, int len) {
//                LOGGER.log(Level.FINEST, () -> "read(...," + off + "," + len + ") called.");
//                int ret = -1;
//                try {
//                    ret = inputStream.read(b, off, len);
//                } catch (IOException ex) {
//                    Logger.getLogger(CRCLSocket.class.getName()).log(Level.SEVERE, null, ex);
//                }
//                final int retf = ret;
//                if (ret > 0) {
//                    final byte bf[] = b;
//                    LOGGER.log(Level.FINEST, () -> "b = " + Arrays.toString(Arrays.copyOf(bf, retf)));
//                }
//                LOGGER.log(Level.FINEST, () -> "read(...," + off + "," + len + ") returning " + retf);
//                return ret;
//            }
//
//            @Override
//            public int read(byte[] b) throws IOException {
//                LOGGER.log(Level.FINEST, () -> "read(...,) called.");
//                int ret = inputStream.read(b);
//                final int retf = ret;
//                if (ret > 0) {
//                    final byte bf[] = b;
//                    LOGGER.log(Level.FINEST, () -> "b = " + Arrays.toString(Arrays.copyOf(bf, retf)));
//                }
//                
//                LOGGER.log(Level.FINEST, () -> "read(...) returning " + retf);
//                return ret;
//            }
//        };
        exiStatusInSaxSource = new SAXSource(xmlReader, new InputSource(is));
        return exiStatusInSaxSource;
    }

    public CRCLCommandInstanceType readCommandFromEXIStream(final InputStream inputStream)
            throws EXIException, JAXBException, IOException {

        synchronized (u_cmd) {
            JAXBElement<CRCLCommandInstanceType> el
                    = u_cmd.unmarshal(getExiCommandInSaxSource(inputStream), CRCLCommandInstanceType.class);
            return el.getValue();
        }
    }

    public CRCLStatusType readStatus() throws JAXBException, IOException, EXIException {
        return readStatus(false);
    }
    
    public CRCLStatusType readStatus(boolean validate)
            throws JAXBException, IOException, EXIException {
        if (this.isEXIEnabled()) {
            if (this.isPrefixEXISizeEnabled()) {
                int size = 0;
//            String str = "";
                byte sizeba[] = new byte[4];
//                LOGGER.log(Level.FINEST,() ->"readStatus: sizeba = " + Arrays.toString(sizeba));
                int r1 = getBufferedInputStream().read(sizeba);
//                LOGGER.log(Level.FINEST,() ->"readStatus: r1 = " + r1);
//                LOGGER.log(Level.FINEST,() ->"readStatus: sizeba = " + Arrays.toString(sizeba));
//                str +=  new String(sizeba);
//                LOGGER.log(Level.FINEST,() ->"str = " + str);
//                LOGGER.log(Level.FINEST,() ->"readStatus: sizeba as String = " + new String(sizeba));
                ByteBuffer bb = ByteBuffer.wrap(sizeba);
                size = bb.getInt();
//                LOGGER.log(Level.FINEST,() ->"readStatus: size = " + size);
                byte ba[] = new byte[size];
                int r2 = getBufferedInputStream().read(ba);
//                LOGGER.log(Level.FINEST,() ->"r2 = " + r2);
//                LOGGER.log(Level.FINEST,() ->"readStatus: ba.length = " + ba.length);
//                LOGGER.log(Level.FINEST,() ->"readStatus: ba = " + Arrays.toString(ba));
                return exiToStatus(ba);
            } else {
                return this.readStatusFromEXIStream(getBufferedInputStream());
            }
        }
//        return readStatusFromStream(getBufferedInputStream(), validate);
        this.lastStatusString = this.readUntilEndTag("CRCLStatus", getBufferedInputStream());
        if (null == this.lastStatusString) {
            return null;
        }
        return stringToStatus(this.lastStatusString, validate);
    }

    private final ObjectFactory objectFactory
            = new ObjectFactory();

    public String commandToString(CRCLCommandType cmd, boolean validate) {
        try {
            CRCLCommandInstanceType instance = new CRCLCommandInstanceType();
            instance.setCRCLCommand(cmd);
            String str = removeHeader(this.commandToString(instance, validate));
            if (str.endsWith("</CRCLCommandInstance>")) {
                str = str.substring(0, str.length() - "</CRCLCommandInstance>".length());
            }
            return str;
        } catch (Exception ex) {
        }
        return "";
    }

    public String commandToString(CRCLCommandInstanceType cmd, boolean validate) throws JAXBException {
        JAXBElement<CRCLCommandInstanceType> jaxb_cmd
                = objectFactory.createCRCLCommandInstance(cmd);
        StringWriter sw = new StringWriter();
        String ret = null;
        synchronized (m_cmd) {
            m_cmd.setSchema(validate ? cmdSchema : null);
            m_cmd.marshal(jaxb_cmd, sw);
            String str = sw.toString();
            if (replaceHeader) {
                str = removeHeader(str);
                ret = cmdHeader + str;
            } else {
                ret = str;
            }
        }
        this.lastCommandString = ret;
        return ret;
    }

    public String programToString(CRCLProgramType prog, boolean validate) throws JAXBException {
        JAXBElement<CRCLProgramType> jaxb_prog
                = objectFactory.createCRCLProgram(prog);
        StringWriter sw = new StringWriter();
        synchronized (m_prog) {
            m_prog.setSchema(validate ? programSchema : null);
            m_prog.marshal(jaxb_prog, sw);
            String str = sw.toString();
            if (replaceHeader) {
                str = removeHeader(str);
                this.lastProgramString = progHeader + str;
            } else {
                this.lastProgramString = str;
            }
        }
        return this.lastProgramString;
    }

    public String commandToPrettyString(CRCLCommandInstanceType cmd, boolean validate) throws JAXBException {
        JAXBElement<CRCLCommandInstanceType> jaxb_cmd
                = objectFactory.createCRCLCommandInstance(cmd);
        StringWriter sw = new StringWriter();
        String ret = null;
        synchronized (m_cmd) {
            m_cmd.setSchema(validate ? cmdSchema : null);
            m_cmd.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
            m_cmd.marshal(jaxb_cmd, sw);
            m_cmd.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, false);
            String str = sw.toString();
            if (replaceHeader) {
                str = removeHeader(str);
                ret = cmdHeader + str;
            } else {
                ret = str;
            }
        }
        this.lastCommandString = ret;
        return ret;
    }

    public String commandToPrettyDocString(CRCLCommandInstanceType cmd, boolean validate) throws JAXBException {
        JAXBElement<CRCLCommandInstanceType> jaxb_cmd
                = objectFactory.createCRCLCommandInstance(cmd);
        StringWriter sw = new StringWriter();
        String ret = null;
        synchronized (m_cmd) {
            m_cmd.setSchema(validate ? cmdSchema : null);
            m_cmd.setProperty(Marshaller.JAXB_FRAGMENT, false);
            m_cmd.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
            m_cmd.marshal(jaxb_cmd, sw);
            m_cmd.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, false);
            m_cmd.setProperty(Marshaller.JAXB_FRAGMENT, jaxbFragment);
            String str = sw.toString();
            if (replaceHeader) {
                str = removeHeader(str);
                ret = cmdHeader + str;
            } else {
                ret = str;
            }
        }
        this.lastCommandString = ret;
        return ret;
    }

    public String programToPrettyString(CRCLProgramType prog, boolean validate) throws JAXBException {
        JAXBElement<CRCLProgramType> jaxb_prog
                = objectFactory.createCRCLProgram(prog);
        StringWriter sw = new StringWriter();
        synchronized (m_prog) {
            m_prog.setSchema(validate ? programSchema : null);
            m_prog.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
            m_prog.marshal(jaxb_prog, sw);
            m_prog.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, false);
            String str = sw.toString();
            if (replaceHeader) {
                str = removeHeader(str);
                this.lastProgramString = progHeader + str;
            } else {
                this.lastProgramString = str;
            }
        }
        return this.lastProgramString;
    }

    public String programToPrettyDocString(CRCLProgramType prog, boolean validate) throws JAXBException {
        JAXBElement<CRCLProgramType> jaxb_proj
                = objectFactory.createCRCLProgram(prog);
        StringWriter sw = new StringWriter();
        synchronized (m_prog) {
            m_prog.setSchema(validate ? programSchema : null);
            m_prog.setProperty(Marshaller.JAXB_FRAGMENT, false);
            m_prog.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
            m_prog.marshal(jaxb_proj, sw);
            m_prog.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, false);
            m_prog.setProperty(Marshaller.JAXB_FRAGMENT, jaxbFragment);
            String str = sw.toString();
            if (replaceHeader) {
                str = removeHeader(str);
                this.lastProgramString = progHeader + str;
            } else {
                this.lastProgramString = str;
            }
        }
        return this.lastProgramString;
    }

    public void writeCommand(CRCLCommandInstanceType cmd) throws JAXBException, IOException, InterruptedException, EXIException {
        writeCommand(cmd,false);
    }
    
    public synchronized void writeCommand(CRCLCommandInstanceType cmd, boolean validate) throws JAXBException, IOException, InterruptedException, EXIException {
        final CRCLCommandType cc = cmd.getCRCLCommand();
        final boolean EXI = this.isEXIEnabled();
        final String threadName = Thread.currentThread().getName();
        final Level loglevel = (cc instanceof GetStatusType) ? Level.FINER : Level.FINE;
        LOGGER.log(loglevel,
                () -> "writeCommand(" + cc + " ID=" + cc.getCommandID() + ") with EXI = " + EXI + " called from Thread: " + threadName);
        if (this.isEXIEnabled()) {
            if (!this.isPrefixEXISizeEnabled()) {
                this.writeEXICommandToStream(sock.getOutputStream(), cmd);
            } else {
                final byte ba[] = this.commandToEXI(cmd);
                LOGGER.log(loglevel, () -> "writeCommand() : ba = " + Arrays.toString(ba));
                ByteBuffer bb = ByteBuffer.allocate(ba.length + 4);
                bb.putInt(ba.length);
//                LOGGER.log(Level.FINEST,() ->"writeCommand: ba.length = " + ba.length);
                bb.put(ba);
                byte ba2[] = bb.array();
//                LOGGER.log(Level.FINEST,() ->"writeCommand: ba2.length = " + ba2.length);
//                LOGGER.log(Level.FINEST,() ->"writeCommand: ba2 = " + Arrays.toString(ba2));
                this.sock.getOutputStream().write(ba2);
                this.sock.getOutputStream().flush();
            }
            return;

        }
        final String str = commandToString(cmd, validate);
        LOGGER.log(loglevel,
                () -> "writeCommand(" + cc + " ID=" + cc.getCommandID() + ") with str = " + str + " called from Thread: " + threadName);
        writeWithFill(str);
        this.lastCommandString = str;
    }

    static public boolean DEFAULT_APPEND_TRAILING_ZERO = false;
    public boolean appendTrailingZero = DEFAULT_APPEND_TRAILING_ZERO;

    static public boolean DEFAULT_RANDOM_PACKETING = false;
    public boolean randomPacketing = DEFAULT_RANDOM_PACKETING;
    private Random random = null;
    public int rand_seed = 12345;

    private void writePackets(OutputStream os, byte ba[]) throws IOException, InterruptedException {
        if (!this.randomPacketing) {
            os.write(ba);
        } else {
            if (null == random) {
                random = new Random(rand_seed);
            }
            int bytes_written = 0;
            while (bytes_written < ba.length) {
                int bytes_to_write = random.nextInt(ba.length);
                if (bytes_to_write >= ba.length - bytes_written) {
                    bytes_to_write = ba.length - bytes_written;
                }
                os.write(ba, bytes_written, bytes_to_write);
                bytes_written += bytes_to_write;
                if (bytes_written < ba.length) {
                    os.flush();
                    Thread.sleep(random.nextInt(150));
                }
            }
        }
    }
//    static final byte fill[] = new byte[2000];
//    static final private byte zeroba[] = new byte[1];

    public void writeWithFill(String str) throws IOException, InterruptedException {
        OutputStream os = sock.getOutputStream();
//        String strout = "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n"+str;
        synchronized (os) {
            if (!appendTrailingZero) {
                this.writePackets(os, str.getBytes());
            } else {
                int len = str.length();
                byte bytesPlusOne[] = new byte[len + 1];
                System.arraycopy(str.getBytes(), 0, bytesPlusOne, 0, len);
                this.writePackets(os, bytesPlusOne);
            }
//            os.write(zeroba);
//            os.write(fill,len,fill.length -len-1);
            os.flush();
        }
    }

    public void writeProgram(CRCLProgramType prog, boolean validate) throws JAXBException, IOException, InterruptedException {
        this.lastProgramString = programToString(prog, validate);
        this.writeWithFill(this.lastProgramString);
    }

    private String last_xml_version_header = null;
    private String last_orig_first_tag = null;

    private boolean replaceHeader;

    /**
     * Get the value of replaceHeader
     *
     * @return the value of replaceHeader
     */
    public boolean isReplaceHeader() {
        return replaceHeader;
    }

    /**
     * Set the value of replaceHeader
     *
     * @param replaceHeader new value of replaceHeader
     */
    public void setReplaceHeader(boolean replaceHeader) {
        this.replaceHeader = replaceHeader;
    }

    public String statusToString(CRCLStatusType status, boolean validate) throws JAXBException {
        JAXBElement<CRCLStatusType> jaxb_status
                = objectFactory.createCRCLStatus(status);
        StringWriter sw = new StringWriter();
        synchronized (m_stat) {
            m_stat.setSchema(validate ? statSchema : null);
            try {
                m_stat.marshal(jaxb_status, sw);
            } catch (Exception ex1) {
                LOGGER.log(Level.SEVERE,
                        "First Exception validate=" + validate + " sw.toString() = " + sw.toString() + ",status=" + statToDebugString(status),
                        ex1);
                sw = new StringWriter();
                try {
                    m_stat.setSchema(null);
                    m_stat.marshal(jaxb_status, sw);
                } catch (Exception ex2) {
                    LOGGER.log(Level.SEVERE, "Second Exception", ex2);
                    return this.lastStatusString;
                }
            }
            String str = sw.toString();
            if (replaceHeader) {
                str = removeHeader(str);
                this.lastStatusString = statusHeader + str;
            } else {
                this.lastStatusString = str;
            }
            if (null != this.statusStringOutputFilter) {
                this.lastStatusString = this.statusStringOutputFilter.apply(this.lastStatusString);
            }
            return this.lastStatusString;
        }
    }

    private String removeHeader(String str) {
        int qgtindex = str.indexOf("?>");
        if (qgtindex > 0) {
            last_xml_version_header = str.substring(0, qgtindex + 2);
            str = str.substring(qgtindex + 2);
        }
        int gtindex = str.indexOf('>');
        if (gtindex > 0) {
            last_orig_first_tag = str.substring(0, gtindex + 1);
            str = str.substring(gtindex + 1);
        }
        return str;
    }

    public String statusToPrettyString(CRCLStatusType status, boolean validate) throws JAXBException {
        JAXBElement<CRCLStatusType> jaxb_status
                = objectFactory.createCRCLStatus(status);
        StringWriter sw = new StringWriter();
        synchronized (m_stat) {
            m_stat.setSchema(validate ? statSchema : null);
            m_stat.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, true);
            m_stat.marshal(jaxb_status, sw);
            m_stat.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, false);
            String str = sw.toString();
            if (replaceHeader) {
                str = removeHeader(str);
                this.lastStatusString = statusHeader + str;
            } else {
                this.lastStatusString = str;
            }
            if (null != this.statusStringOutputFilter) {
                this.lastStatusString = this.statusStringOutputFilter.apply(this.lastStatusString);
            }
            return this.lastStatusString;
        }
    }

    private static final File crclSchemaDirFile;

    static {
        File startFile = new File(System.getProperty("user.home"));
        crclSchemaDirFile = new File(startFile, String.join(File.separator, "crclXmlSchemas"));
    }

    public static File[] findSchemaFiles() {
        copySchemaResources();
        if (crclSchemaDirFile.exists()) {
            return crclSchemaDirFile.listFiles(new FileFilter() {

                @Override
                public boolean accept(File pathname) {
                    return pathname.getName().endsWith(".xsd");
                }
            });
        }
        return null;
    }

    private static boolean resourcesCopied = false;

    private static void copySchemaResources() {
        if (resourcesCopied) {
            return;
        }
        crclSchemaDirFile.mkdirs();
        copyResourcesToFiles(crclSchemaDirFile,
                "CRCLCommandInstance.xsd",
                "CRCLCommands.xsd",
                "CRCLProgramInstance.xsd",
                "DataPrimitives.xsd",
                "CRCLStatus.xsd");
        resourcesCopied = true;
    }

    /**
     *
     * @param dirFile the value of dirFile
     * @param names the value of names
     */
    private static void copyResourcesToFiles(File dirFile, String... names) {
        dirFile.mkdirs();
        ClassLoader classLoader = CRCLStatusType.class.getClassLoader();
        for (String name : names) {
            try {
                File f = new File(dirFile, name);
                if (f.exists() && (f.lastModified() - System.currentTimeMillis()) < 60000) {
                    continue;
                }
                org.apache.commons.io.FileUtils.copyInputStreamToFile(
                        classLoader.getResourceAsStream(name),
                        f);
            } catch (MalformedURLException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                LOGGER.log(Level.SEVERE, null, ex);
            }
        }
    }

    public static List<File> reorderStatSchemaFiles(List<File> fl) {
        Collections.sort(fl, new Comparator<File>() {

            @Override
            public int compare(File o1, File o2) {
                return o1.getName().compareTo(o2.getName());
            }
        });
        int statIndex = -1;
        for (int i = 0; i < fl.size(); i++) {
            if (fl.get(i).getName().contains("Status")) {
                statIndex = i;
                break;
            }
        }
        if (statIndex > 0 && statIndex < fl.size()) {
            File f = fl.remove(statIndex);
            fl.add(0, f);
        }
        return fl;
    }

    public static File[] reorderStatSchemaFiles(File fa[]) {
        if (null == fa || fa.length < 1) {
            return fa;
        }
        List<File> fl = new ArrayList<>();
        fl.addAll(Arrays.asList(fa));
        return reorderStatSchemaFiles(fl).toArray(fa);
    }

    public static Schema filesToSchema(File fa[]) throws SAXException {
        Source sources[] = new Source[fa.length];
        for (int i = 0; i < sources.length; i++) {
            sources[i] = new StreamSource(fa[i]);
        }
        SchemaFactory schemaFactory = SchemaFactory
                .newInstance(XMLConstants.W3C_XML_SCHEMA_NS_URI);
        return schemaFactory.newSchema(sources);
    }

    public static File[] readStatSchemaFiles(File schemaListFile) {
        if (schemaListFile.exists() && System.currentTimeMillis() - schemaListFile.lastModified() > 60000) {
            schemaListFile.delete();
            saveStatSchemaFiles(schemaListFile, findSchemaFiles());
        } else if (!schemaListFile.exists()) {
            saveStatSchemaFiles(schemaListFile, findSchemaFiles());
        }
        if (!schemaListFile.exists()) {
//            showMessage("Could not find CRCL Schema xsd files.");
            return null;
        }
        try (BufferedReader br = new BufferedReader(new FileReader(schemaListFile))) {
            String line = null;
            List<File> fl = new ArrayList<>();
            while (null != (line = br.readLine())) {
                fl.add(new File(line.trim()));
            }
            fl = reorderStatSchemaFiles(fl);
            return fl.toArray(new File[fl.size()]);
        } catch (FileNotFoundException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
        return null;
    }

    public static void saveProgramSchemaFiles(File schemaListFile, File fa[]) {
        if (null == fa) {
            return;
        }
        fa = reorderProgramSchemaFiles(fa);
        try (PrintStream ps = new PrintStream(new FileOutputStream(schemaListFile))) {
            for (int i = 0; i < fa.length; i++) {
                ps.println(fa[i].getCanonicalPath());
            }
        } catch (FileNotFoundException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    public static void saveStatSchemaFiles(File schemaListFile, File fa[]) {
        if (null == fa) {
            return;
        }
        fa = reorderStatSchemaFiles(fa);
        try (PrintStream ps = new PrintStream(new FileOutputStream(schemaListFile))) {
            for (int i = 0; i < fa.length; i++) {
                ps.println(fa[i].getCanonicalPath());
            }
        } catch (FileNotFoundException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    public static File[] reorderCommandSchemaFiles(File[] fa) {
        if (null == fa || fa.length < 1) {
            return fa;
        }
        List<File> fl = new ArrayList<>();
        fl.addAll(Arrays.asList(fa));
        return reorderCommandSchemaFiles(fl).toArray(fa);
    }

    public static List<File> reorderCommandSchemaFiles(List<File> fl) {
        Collections.sort(fl, new Comparator<File>() {

            @Override
            public int compare(File o1, File o2) {
                return o1.getName().compareTo(o2.getName());
            }
        });
        int cmdInstanceIndex = -1;
        for (int i = 0; i < fl.size(); i++) {
            if (fl.get(i).getName().contains("CommandInstance")) {
                cmdInstanceIndex = i;
                break;
            }
        }
        if (cmdInstanceIndex > 0 && cmdInstanceIndex < fl.size()) {
            File f = fl.remove(cmdInstanceIndex);
            CRCLSocket.commandXsdFile = f;
            fl.add(0, f);
        }
        return fl;
    }

    public static File[] reorderProgramSchemaFiles(File[] fa) {
        List<File> fl = new ArrayList<>();
        fl.addAll(Arrays.asList(fa));
        return reorderProgramSchemaFiles(fl).toArray(fa);
    }

    public static List<File> reorderProgramSchemaFiles(List<File> fl) {
        Collections.sort(fl, new Comparator<File>() {

            @Override
            public int compare(File o1, File o2) {
                return o1.getName().compareTo(o2.getName());
            }
        });
        int cmdInstanceIndex = -1;
        for (int i = 0; i < fl.size(); i++) {
            if (fl.get(i).getName().contains("ProgramInstance")) {
                cmdInstanceIndex = i;
                break;
            }
        }
        if (cmdInstanceIndex > 0 && cmdInstanceIndex < fl.size()) {
            File f = fl.remove(cmdInstanceIndex);
            CRCLSocket.commandXsdFile = f;
            fl.add(0, f);
        }
        return fl;
    }

    public static File[] readCmdSchemaFiles(File schemasListFile) {
        if (schemasListFile.exists() && System.currentTimeMillis() - schemasListFile.lastModified() > 60000) {
            schemasListFile.delete();
            saveCmdSchemaFiles(schemasListFile, findSchemaFiles());
        } else if (!schemasListFile.exists()) {
            saveCmdSchemaFiles(schemasListFile, findSchemaFiles());
        }
        if (!schemasListFile.exists()) {
//            showMessage("Could not find CRCL Schema xsd files.");
            return null;
        }
        try (BufferedReader br = new BufferedReader(new FileReader(schemasListFile))) {
            String line = null;
            List<File> fl = new ArrayList<>();
            while (null != (line = br.readLine())) {
                fl.add(new File(line.trim()));
            }
            fl = reorderCommandSchemaFiles(fl);
            return fl.toArray(new File[fl.size()]);
        } catch (FileNotFoundException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
        return null;
    }

    public static File[] readProgramSchemaFiles(File schemasListFile) {
        if (!schemasListFile.exists()) {
            saveCmdSchemaFiles(schemasListFile, findSchemaFiles());
            return null;
        }
        if (!schemasListFile.exists()) {
//            showMessage("Could not find CRCL Schema xsd files.");
            return null;
        }
        try (BufferedReader br = new BufferedReader(new FileReader(schemasListFile))) {
            String line = null;
            List<File> fl = new ArrayList<>();
            while (null != (line = br.readLine())) {
                fl.add(new File(line.trim()));
            }
            fl = reorderCommandSchemaFiles(fl);
            return fl.toArray(new File[fl.size()]);
        } catch (FileNotFoundException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
        return null;
    }

    public static void saveCmdSchemaFiles(File schemasListFile, File fa[]) {
        if (null == fa) {
            return;
        }
        try (PrintStream ps = new PrintStream(new FileOutputStream(schemasListFile))) {
            for (int i = 0; i < fa.length; i++) {
                ps.println(fa[i].getCanonicalPath());
            }
        } catch (FileNotFoundException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        } catch (IOException ex) {
            LOGGER.log(Level.SEVERE, null, ex);
        }
    }

    public void writeStatus(CRCLStatusType status, boolean validate)
            throws JAXBException, IOException, InterruptedException, EXIException {
        if (this.isEXIEnabled()) {
            if (this.isPrefixEXISizeEnabled()) {
                byte ba[] = this.statusToEXI(status);
//                LOGGER.log(Level.FINEST,() ->"writeStatus() : ba = " + Arrays.toString(ba));
                ByteBuffer bb = ByteBuffer.allocate(ba.length + 4);
                bb.putInt(ba.length);
//                LOGGER.log(Level.FINEST,() ->"writeStatus: ba.length = " + ba.length);
                bb.put(ba);
                byte ba2[] = bb.array();
//                LOGGER.log(Level.FINEST,() ->"writeStatus: ba2.length = " + ba2.length);
//                LOGGER.log(Level.FINEST,() ->"writeStatus: ba2 = " + Arrays.toString(ba2));
                this.sock.getOutputStream().write(ba2);
                this.sock.getOutputStream().flush();
            } else {
                this.writeEXIStatusToStream(sock.getOutputStream(), status);
            }
            return;
        }
        this.lastStatusString = statusToString(status, validate);
        this.writeWithFill(this.lastStatusString);
    }

//    public OutputStream getOutputStream() throws IOException {
//        return sock.getOutputStream();
//    }
//
//    public InputStream getInputStream() throws IOException {
//        return getBufferedInputStream();
//    }
}
