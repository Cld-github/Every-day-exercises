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
}contact[1000];
int count=0;
void structcpy(struct AddressList *a,struct AddressList *b){//��b���Ƹ�a
	strcpy((*a).name, (*b).name);
	strcpy((*a).sex, (*b).sex);
	(*a).age=(*b).age;
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
void add(){
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
void del(){
	char c[20];
	printf("������Ҫɾ�����˵����֣�");
	scanf("%s", &c);
	int i = 0;
	for (; i < count; i++){
		if (strcmp(c, contact[i].name) == 0){
			for (int j = i; j < count-1; j++){
				structcpy(&contact[j], &contact[j + 1]);
			}
			count--;
			printf("ɾ���ɹ�\n");
			break;
		}
	}
	if(count == i){
		printf("ɾ��ʧ�ܣ����޴���");
	}
}
void find(){
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
void change(){
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
void show(){
	for (int i = 0; i < count; i++){
		print(&contact[i]);
	}
}
void DelAll(){
	count = 0;
	printf("ɾ�����\n");
}
void Sort(){
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
	while (1){
		system("cls");
		printf("�˵���\n");
		printf("1.�����ϵ����Ϣ\n2.ɾ��ָ����ϵ����Ϣ\n3.����ָ����ϵ����Ϣ\n4.�޸�ָ����ϵ����Ϣ\n5.��ʾ������ϵ����Ϣ\n6.���������ϵ��\n7.����������������ϵ��\n");
		printf("���������ѡ�");
		scanf("%d", &a);
		switch (a)
		{
		case 1:add();
			break;
		case 2:del();
			break;
		case 3:find();
			break;
		case 4:change();
			break;
		case 5:show();
			break;
		case 6:DelAll();
			break;
		case 7:Sort();
			break;
		default:
			break;
		}
		system("pause");
	}
}