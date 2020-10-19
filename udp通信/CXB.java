package p2p3;
import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.UnknownHostException;
import java.net.SocketException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.ServerSocket;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.FlowLayout;
import java.awt.Color;
import java.awt.Font;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JTextField;
import javax.swing.JTextArea;
import javax.swing.JScrollPane;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.IOException;
class QQ_UDP implements ActionListener,Runnable
{
JFrame JFm = new JFrame("P2P�������˲��� ");
JTextArea dialogArea = new JTextArea();
JScrollPane JSP = new JScrollPane(dialogArea);//Ϊ�������� ��ӹ��� ����,��������Զ��Ļ��У� �ͱ����ù�����
JLabel Goal_IP_lable = new JLabel("Ŀ��IP��ַ�� ");
JLabel Send_port_lable = new JLabel("���Ͷ˿ڣ� ");
JLabel Receive_port_lable = new JLabel("���ն˿ڣ� ");
JTextField msgField,sendPortField,receivePortField,Goal_IP_Field;
JButton startJBt = new JButton("��ʼ");
JButton sendJBt = new JButton("����");
JPanel Jpl_North,Jpl_South;//�ϱ����
Thread Td = null;
DatagramPacket sendPack,receivePack;
DatagramSocket sendSocket,receiveSocket;
InetAddress goal_IP;
int sendPort,receivePort;
byte inBuf[] = new byte[1024];
byte outBuf[] = new byte[1024];
Socket ToQQClient;
 ServerSocket serverSocket;
DataInputStream inFromQQClient;
DataOutputStream outToQQClient;
public QQ_UDP()
{
dialogArea.setEditable(false);//���ɱ༭
dialogArea.setLineWrap(true);//�Զ�����
dialogArea.setBackground(Color.WHITE);
dialogArea.setFont(new Font("����",Font.BOLD,18));
sendPortField = new JTextField();
sendPortField.setColumns(5);
receivePortField = new JTextField();
receivePortField.setColumns(5);
Goal_IP_Field = new JTextField();
Goal_IP_Field.setColumns(8);
startJBt.addActionListener(this);
Jpl_North = new JPanel();
Jpl_North.setLayout(new FlowLayout());
Jpl_North.setBackground(Color.BLUE);
Jpl_North.add(Receive_port_lable);
Jpl_North.add(receivePortField);
Jpl_North.add(Send_port_lable);
Jpl_North.add(sendPortField);
Jpl_North.add(Goal_IP_lable);
Jpl_North.add(Goal_IP_Field);
Jpl_North.add(startJBt);
msgField = new JTextField();
msgField.setColumns(40);
msgField.setEditable(false);
msgField.addActionListener(this);
sendJBt.setEnabled(false);
sendJBt.addActionListener(this);
Jpl_South = new JPanel();
Jpl_South.setLayout(new FlowLayout());
Jpl_South.setBackground(Color.BLUE);
Jpl_South.add(msgField);
Jpl_South.add(sendJBt);
JFm.add(JSP,BorderLayout.CENTER);
JFm.add(Jpl_North,BorderLayout.NORTH);
JFm.add(Jpl_South,BorderLayout.SOUTH);
JFm.setSize(600,400);
JFm.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
JFm.setVisible(true);
}
 public void actionPerformed(ActionEvent e)
{
try
{
if(e.getSource()==startJBt)//�����ʼ
{
sendPort = Integer.parseInt(sendPortField.getText());
goal_IP = InetAddress.getByName(Goal_IP_Field.getText());
sendSocket = new DatagramSocket();//�������ݱ��׽��ֲ�����󶨵������������κο��õĶ˿ڡ�
receivePort = Integer.parseInt(receivePortField.getText());
receivePack = new DatagramPacket(inBuf,1024);//���ճ���Ϊ length �����ݰ�
receiveSocket = new DatagramSocket(receivePort);//�������ݱ��׽��ֲ�����󶨵����������ϵ�ָ���˿ڡ�
Td = new Thread(this);
Td.setPriority(Thread.MIN_PRIORITY);
Td.start();
startJBt.setEnabled(false);
sendJBt.setEnabled(true);
msgField.setEditable(true);
}
else//������ͻ��� ���س�
{
outBuf = msgField.getText().getBytes();
sendPack = new
DatagramPacket(outBuf,outBuf.length,goal_IP,sendPort);
//����������Ϊ length �İ����͵�ָ�������ϵ�ָ���˿ں�
sendSocket.send(sendPack);
dialogArea.append("�ң� "+msgField.getText()+"\n");
msgField.setText(null);
}
}
catch(UnknownHostException UE)
{
dialogArea.append("�޷����ӵ�ָ����ַ\n");
}
catch(SocketException SE)
{
dialogArea.append("�޷���ָ���˿�\n");
}
catch(IOException IE)
{
dialogArea.append("��������ʧ��\n");
 }
catch(Exception E)
{
dialogArea.append("�˿ڳ�ʼ��ʧ��\n");
}
}
public void run()
{
String St;
while(true)
{
try
{
receiveSocket.receive(receivePack);//��������
St = new String(receivePack.getData(),0,receivePack.getLength());
dialogArea.append(Goal_IP_Field.getText()+":"+St+"\n");
Thread.sleep(1000);
}
catch(IOException IE)
{
dialogArea.append("�������ݳ���");
}
catch(Exception e)
{
dialogArea.append("�̳߳��� "+e);
}
}
}
}
public class CXB
{
public static void main(String args[])
{
new QQ_UDP();
}
}