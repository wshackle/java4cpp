/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package testpackage;

import java.util.Objects;

/**
 *
 * @author Will Shackleford {@literal <william.shackleford@nist.gov>}
 */
public class MyClient {

    private final String host;
    private final int port;

    public MyClient(String host, int port) {
        this.host = host;
        this.port = port;
        System.out.println("Java MyClient(" + host + "," + port + ") constructor called.");
    }

    public int getPort() {
        return port;
    }

    public String getHost() {
        return host;
    }
    
//extends JFrame {
//    public static class PictureData implements Serializable {
//
//        private byte[] data;
//
//        /**
//         * Get the value of data
//         *
//         * @return the value of data
//         */
//        public byte[] getData() {
//            return data;
//        }
//
//        /**
//         * Set the value of data
//         *
//         * @param data new value of data
//         */
//        public void setData(byte[] data) {
//            this.data = data;
//        }
//    }
//
//    
//    MyClient(String host, int port) {
//        try {
//            Socket s= new Socket(host,port);
//            JButton myButton = new JButton("Send Picture");
//            ObjectOutputStream oos = new ObjectOutputStream(s.getOutputStream());
//            myButton.addActionListener(e -> {
//                try {
//                    PictureData pd = new PictureData();
//                    pd.setData(new byte[]{1, 2, 3, 4});
//                    oos.writeObject(pd);
//                } catch (IOException ex) {
//                    ex.printStackTrace();
//                }
//            });
//            add(myButton);
//            pack();
//            setVisible(true);
//        } catch (Exception ex) {
//            ex.printStackTrace();
//        }
//    }
//    
//    public static void main(String[] args) {
//        java.awt.EventQueue.invokeLater(() -> new MyClient("localhost",1234));
//    }

    @Override
    public String toString() {
        return "MyClient{" + "host=" + host + ", port=" + port + '}';
    }

    @Override
    public int hashCode() {
        int hash = 7;
        hash = 37 * hash + Objects.hashCode(this.host);
        hash = 37 * hash + this.port;
        return hash;
    }

    @Override
    public boolean equals(Object obj) {
        if (obj == null) {
            return false;
        }
        if (getClass() != obj.getClass()) {
            return false;
        }
        final MyClient other = (MyClient) obj;
        if (!Objects.equals(this.host, other.host)) {
            return false;
        }
        if (this.port != other.port) {
            return false;
        }
        return true;
    }
    
    
}
