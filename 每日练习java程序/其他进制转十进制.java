import java.util.Scanner;

public class ��������תʮ���� {
	static int GetInt(int a, int b[], String c){
		int i = 0;
		for (; i<c.length(); i++){
			if (c.charAt(i) >= '0' && c.charAt(i) <= '9'){
				b[i] = c.charAt(i) - '0';
			}
			else if (c.charAt(i) >= 'a'&&c.charAt(i) <= 'z'){
				b[i] = c.charAt(i) - 'a'+10;
			}
			else return 0;
			if (b[i] >= a) return 0;
		}
		b[i] = -1;
		return 1;
	}
	static int Change(int a,int b[]){
		int s = b[0];
		for (int i = 1; b[i]!=-1; i++){
			s *= a;
			s += b[i];
		}
		return s;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//char c[20];
		//int a, b[20];
		int []b=new int[20];
		Scanner scanner=new Scanner(System.in);
		System.out.println("�������������");
		int a=scanner.nextInt();
		System.out.println("������ý��Ƶ����֣�");
		String c=scanner.next();
		if (GetInt(a, b, c) == 0){
			System.out.println("���ִ���!");
		}
		else {
			System.out.printf("����ת��������ǣ�%d", Change(a, b));
		}
	}

}
