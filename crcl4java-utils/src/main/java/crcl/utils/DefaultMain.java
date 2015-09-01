/*
 * This software is public domain software, however it is preferred
 * that the following disclaimers be attached.
 * Software Copywrite/Warranty Disclaimer
 * 
 * This software was developed at the National Institute of Standards and
 * Technology by employees of the Federal Government in the course of their
 * official duties. Pursuant to title 17 Section 105 of the United States
 * Code this software is not subject to copyright protection and is in the
 * public domain. NIST Real-Time Control System software is an experimental
 * system. NIST assumes no responsibility whatsoever for its use by other
 * parties, and makes no guarantees, expressed or implied, about its
 * quality, reliability, or any other characteristic. We would appreciate
 * acknowledgement if the software is used. This software can be
 * redistributed and/or modified freely provided that any derivative works
 * bear some notice that they are derived from it, and any modified
 * versions bear some notice that they have been modified.
 * 
 *  See http://www.copyright.gov/title17/92chap1.html#105
 * 
 */
package crcl.utils;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class DefaultMain {

    public static void main(String[] args) {
        String mode = "Launcher";
        for (int i = 0; i < args.length; i++) {
            if (i < args.length - 1) {
                if (args[i].compareTo("--port") == 0 || args[i].compareTo("-p") == 0) {
                    try {
                        int porti = Integer.valueOf(args[i + 1]);
                        if(porti < 1) {
                            System.err.println("port ("+porti+") must be positive.");
                        }
                        System.setProperty("crcljava.port", Integer.toString(porti));
                    } catch (NumberFormatException numberFormatException) {
                        System.err.println("port\"("+args[i+1]+"\" must be an integer");
                        System.exit(i);
                    }
                    i++;
                    continue;
                } else if (args[i].compareTo("--host") == 0 || args[i].compareTo("-h") == 0) {
                    System.setProperty("crcljava.host", args[i + 1]);
                    i++;
                    continue;
                } else if (args[i].compareTo("--program") == 0) {
                    System.setProperty("crcljava.program", args[i + 1]);
                    i++;
                    continue;
                } else if (args[i].compareTo("--mode") == 0 || args[i].compareTo("-m") == 0) {
                    mode = args[i + 1];
                    i++;
                    continue;
                }
            }
            if (args[i].startsWith("-")) {
                System.err.println("Unrecognized argument : " + args[i]);
                System.err.println("Options are:");
                System.err.println("\t--port\tSet main tcp port.");
                System.err.println("\t--host\tSet tcp port used by client to connect.");
                System.err.println("\t--program\tSet xml program file to be sent by client one command at a time.");
                System.err.println("\t--mode\tSet mode to one of:"
                        +"\n\t\tLauncher,CmdLineClient,CmdLineServer,GraphicalServer,GraphicalClient");
                System.exit(1);
            }
        }
        switch (mode) {
            case "Launcher":
                LauncherJFrame.main(args);
                break;

            case "CmdLineClient":
                CmdLineClient.main(args);
                break;

            case "CmdLineServer":
                CmdLineSimServer.main(args);
                break;

            case "GraphicalServer":
                SimServer.main(args);
                break;

            case "GraphicalClient":
                PendantClient.main(args);
                break;
                
            default:
                System.err.println("Unrecognized mode:"+mode);
                System.err.println("Options are:");
                System.err.println("\t--port\tSet main tcp port.");
                System.err.println("\t--host\tSet tcp port used by client to connect.");
                System.err.println("\t--mode\tSet mode to one of:"
                        +"\n\t\tLauncher,CmdLineClient,CmdLineServer,GraphicalServer,GraphicalClient");
                System.exit(1);
        }
    }
}
