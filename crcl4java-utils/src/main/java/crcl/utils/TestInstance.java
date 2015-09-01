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


import crcl.base.CRCLCommandInstanceType;
import crcl.base.CRCLCommandType;
import crcl.base.EndCanonType;
import crcl.base.InitCanonType;
import crcl.base.MoveThroughToType;
import crcl.base.ObjectFactory;
import crcl.base.PoseType;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.math.BigInteger;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.xml.bind.JAXBContext;
import javax.xml.bind.JAXBElement;
import javax.xml.bind.JAXBException;
import javax.xml.bind.Marshaller;
import javax.xml.bind.Unmarshaller;

/**
 *
 * @author Will Shackleford{@literal <william.shackleford@nist.gov> }
 */
public class TestInstance {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        try {
            System.out.println("This program is just for testing. Pass it an xml instance file for crcl and it will print some info.");
            for (String arg : args) {
                JAXBContext jc = JAXBContext.newInstance("crcl");
                Unmarshaller u = jc.createUnmarshaller();
                JAXBElement el = (JAXBElement) u.unmarshal(new FileInputStream(arg));
                CRCLCommandInstanceType instance
                        = (CRCLCommandInstanceType) el.getValue();
                System.out.println("instance = " + instance);
                CRCLCommandType cmd = instance.getCRCLCommand();
                System.out.println("cmd = " + cmd);
                System.out.println("cmd.getCommandID() = " + cmd.getCommandID());
                if(cmd instanceof InitCanonType) {
                        InitCanonType init = (InitCanonType) cmd;
                        System.out.println("INIT");
                } else if(cmd instanceof EndCanonType) {
                        EndCanonType end = (EndCanonType) cmd;
                        System.out.println("END");
                } else if(cmd instanceof MoveThroughToType) {
                        MoveThroughToType mv = (MoveThroughToType) cmd;
                        System.out.println("MoveThroughToType");
                        System.out.println("mv.getNumPositions() = " + mv.getNumPositions());
                        System.out.println("mv.isMoveStraight() = " + mv.isMoveStraight());
                        List<PoseType> wpts = mv.getWaypoint();
                        System.out.println("wpts = " + wpts);
                        if(null != wpts) {
                            for(PoseType pol : wpts) {
                                System.out.println("pol = " + pol);
                                System.out.println("pol.getPoint().getX() = " + pol.getPoint().getX());
                                System.out.println("pol.getPoint().getY() = " + pol.getPoint().getY());
                                System.out.println("pol.getPoint().getZ() = " + pol.getPoint().getZ());
                            }
                        }
                        
                }else {
                        System.err.println("Unrecognize type");
                }
                System.out.println("");
//            System.out.println("init = " + init.getName());
                Marshaller m = jc.createMarshaller();
                ObjectFactory of = new ObjectFactory();
                m.setProperty(Marshaller.JAXB_FORMATTED_OUTPUT, Boolean.TRUE);
                cmd.setCommandID(cmd.getCommandID().add(BigInteger.ONE));
                m.marshal(of.createCRCLCommandInstance(instance), System.out);
            }
        } catch (JAXBException ex) {
            Logger.getLogger(TestInstance.class.getName()).log(Level.SEVERE, null, ex);
        } catch (FileNotFoundException ex) {
            Logger.getLogger(TestInstance.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

}
