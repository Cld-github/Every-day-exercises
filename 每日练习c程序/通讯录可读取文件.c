//��ҵ����
//ʵ��һ��ͨѶ¼;
//ͨѶ¼���������洢1000���˵���Ϣ��ÿ���˵���Ϣ����:�������Ա����䡢�绰��סַ
//�ṩ���� :
//								1.�����ϵ����Ϣ
//								2.ɾ��ָ����ϵ����Ϣ
//								3.����ָ����ϵ����Ϣ
//								4.�޸�ָ����ϵ����Ϣ
//								5.��ʾ������ϵ����Ϣ
//								6.���������ϵ��
//								7.����������������ϵ��

#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
struct AddressList{
	char name[20];
	char sex[5];
	int age;
	char telephone[20];
	char address[20];
};
//struct add{
//	char name[64];
//	char sex[10];
//	int age;
//	int telephone[11];
//	char address[64];
//};
int count = 0, num = 4;
//int init(struct add *s, int n){
//	int count = 0;
//	FILE *f = fopen("F:\\addressbook.txt", "w");
//	if (f == NULL){
//		printf("open file failed!\n");
//		exit(1);
//	}
//	else{
//		printf("open file succeed!\n");
//		while (!feof(f)){
//			(s) = (struct add *) malloc(sizeof(struct add)*(count + 1));
//			fwrite((s+count), sizeof(struct add), 1, f);
//			count++;
//		}return count - 1;
//
//	}fclose(f);
//}

void structcpy(struct AddressList *a, struct AddressList *b){//��b���Ƹ�a
	strcpy((*a).name, (*b).name);
	strcpy((*a).sex, (*b).sex);
	(*a).age = (*b).age;
	strcpy((*a).telephone, (*b).telephone);
	strcpy((*a).address, (*b).address);
}
void print(struct AddressList *a){
	printf("������%s\n", (*a).name);
	printf("�Ա�%s\n", (*a).sex);
	printf("���䣺%d\n", (*a).age);
	printf("�绰��%s\n", (*a).telephone);
	printf("��ַ��%s\n", (*a).address);
}
void add(struct AddressList *contact){
	printf("���������֣�");
	scanf("%s", contact[count].name);
	printf("�������Ա�");
	scanf("%s", contact[count].sex);
	printf("���������䣺");
	scanf("%d", &contact[count].age);
	printf("������绰��");
	scanf("%s", contact[count].telephone);
	printf("������סַ��");
	scanf("%s", contact[count].address);
	count++;
}
void del(struct AddressList *contact){
	char c[20];
	printf("������Ҫɾ�����˵����֣�");
	scanf("%s", &c);
	int i = 0,count2=count;
	for (; i < count; i++){
		if (strcmp(c, contact[i].name) == 0){
			for (int j = i; j < count - 1; j++){
				structcpy(&contact[j], &contact[j + 1]);
			}
			count--;
			printf("ɾ���ɹ�\n");
			break;
		}
	}
	if (count2 == i){
		printf("ɾ��ʧ�ܣ����޴���");
	}
}
void find(struct AddressList *contact){
	char c[20];
	printf("������Ҫ��ѯ���˵����֣�");
	scanf("%s", &c);
	int i = 0;
	for (; i < count; i++){
		if (strcmp(c, contact[i].name) == 0){
			print(&contact[i]);
			break;
		}
	}
	if (count == i){
		printf("���޴��ˣ���˶Ժ�����\n");
	}
}
void change(struct AddressList *contact){
	char c[20];
	printf("������Ҫ�޸ĵ��˵����֣�");
	scanf("%s", &c);
	int i = 0;
	for (; i < count; i++){
		if (strcmp(c, contact[i].name) == 0){
			printf("�������Ա�");
			scanf("%s", contact[i].sex);
			printf("���������䣺");
			scanf("%d", &contact[i].age);
			printf("������绰��");
			scanf("%s", contact[i].telephone);
			printf("������סַ��");
			scanf("%s", contact[i].address);
			printf("�޸ĳɹ�\n");
			break;
		}
	}
	if (count == i){
		printf("�޸�ʧ�ܣ����޴���\n");
	}
}
void show(struct AddressList *contact){
	for (int i = 0; i < count; i++){
		print(&contact[i]);
	}
}
void DelAll(struct AddressList *contact){
	count = 0;
	printf("ɾ�����\n");
}
void Sort(struct AddressList *contact){
	for (int i = 0; i < count; i++){
		for (int j = 0; j < count - i - 1; j++){
			if (strcmp(contact[j].name, contact[j + 1].name) > 0){
				struct AddressList a;
				structcpy(&a, &contact[j]);
				structcpy(&contact[j], &contact[j + 1]);
				structcpy(&contact[j + 1], &a);
			}
		}
	}
	printf("�������\n");
}
void main(){
	int a;
	FILE *fp;
	FILE *fp2;
	fp = fopen("ͨѶ¼.txt", "r");
	
	struct AddressList *contact = (struct AddressList *)malloc(num*sizeof(struct AddressList));

	while (!feof(fp))                     //��ȡһ�����ݺ�ָ��ָ����һ�����ݣ������ж��Ƿ�ָ�����һ�� 
	{
		fscanf(fp, "%s%s%d%s%s", &contact[count].name,&contact[count].sex,&contact[count].age,&contact[count].telephone,&contact[count].address);
		count++;
		if (count == num){
			num += 20;
			/*struct AddressList *contact2 = (struct AddressList *)malloc(num*sizeof(struct AddressList));
			for (int i = 0; i < count; i++){
				structcpy(&contact2[i], &contact[i]);
			}*/
			contact = (struct AddressList *)realloc(contact, num*sizeof(struct AddressList));
			/*for (int i = 0; i < count; i++){
				structcpy(&contact[i], &contact2[i]);
			}*/
		}
	}
	/*printf("%d", count);
	system("pause");*/
	while (1){
		if (count == num){
			num += 20;
			/*struct AddressList *contact2 = (struct AddressList *)malloc(num*sizeof(struct AddressList));
			for (int i = 0; i < count; i++){
				structcpy(&contact2[i], &contact[i]);
			}*/
			contact = (struct AddressList *)realloc(contact, num*sizeof(struct AddressList));
			/*for (int i = 0; i < count; i++){
				structcpy(&contact[i], &contact2[i]);
			}*/
		}
		system("cls");
		printf("�˵���\n");
		printf("1.�����ϵ����Ϣ\n2.ɾ��ָ����ϵ����Ϣ\n3.����ָ����ϵ����Ϣ\n4.�޸�ָ����ϵ����Ϣ\n5.��ʾ������ϵ����Ϣ\n6.���������ϵ��\n7.����������������ϵ��\n0.�˳�\n");
		printf("���������ѡ�");
		scanf("%d", &a);
		switch (a)
		{
		case 1:add(contact);
			break;
		case 2:del(contact);
			break;
		case 3:find(contact);
			break;
		case 4:change(contact);
			break;
		case 5:show(contact);
			break;
		case 6:DelAll(contact);
			break;
		case 7:Sort(contact);
			break;
		case 0:
			printf("���ڱ����������Ժ�\n");
			fp2 = fopen("ͨѶ¼.txt", "w");
			for (int i = 0; i < count; i++){
				fprintf(fp2, "\n%s %s %d %s %s", &contact[i].name, &contact[i].sex, &contact[i].age, &contact[i].telephone, &contact[i].address);
			}
			if(!(fclose(fp)||fclose(fp2)))
				exit(0);
		default:
			break;
		}
		system("pause");
	}
	
}