public class SarahTest {
    public static void main(String[] args) {
        DatabaseMethods test = new DatabaseMethods();
        DatabaseNode txt = new DatabaseNode(0, null, null, null, null, null, 0, null, null);
        txt = test.fileNode();



        System.out.printf("%d, %s, %s, %s, %s, %s, %d, %s, %s", txt.getID(), txt.getFirstName(), txt.getLastName(),
        txt.getaddress(), txt.getCity(), txt.getState(), txt.getZip(), txt.getEmail(), txt.getPhNum());
    }
}
