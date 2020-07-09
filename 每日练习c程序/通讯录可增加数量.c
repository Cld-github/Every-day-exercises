//作业内容
//实现一个通讯录;
//通讯录可以用来存储1000个人的信息，每个人的信息包括:姓名、性别、年龄、电话、住址
//提供方法 :
//								1.添加联系人信息
//								2.删除指定联系人信息
//								3.查找指定联系人信息
//								4.修改指定联系人信息
//								5.显示所有联系人信息
//								6.清空所有联系人
//								7.以名字排序所有联系人

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
int count=0,num=4;
void structcpy(struct AddressList *a,struct AddressList *b){//把b复制给a
	strcpy((*a).name, (*b).name);
	strcpy((*a).sex, (*b).sex);
	(*a).age=(*b).age;
	strcpy((*a).telephone, (*b).telephone);
	strcpy((*a).address, (*b).address);
}
void print(struct AddressList *a){
	printf("姓名：%s\n", (*a).name);
	printf("性别：%s\n", (*a).sex);
	printf("年龄：%d\n", (*a).age);
	printf("电话：%s\n", (*a).telephone);
	printf("地址：%s\n", (*a).address);
}
void add(struct AddressList *contact){
	printf("请输入名字：");
	scanf("%s", contact[count].name);
	printf("请输入性别：");
	scanf("%s", contact[count].sex);
	printf("请输入年龄：");
	scanf("%d", &contact[count].age);
	printf("请输入电话：");
	scanf("%s", contact[count].telephone);
	printf("请输入住址：");
	scanf("%s", contact[count].address);
	count++;
}
void del(struct AddressList *contact){
	char c[20];
	printf("请输入要删除的人的名字：");
	scanf("%s", &c);
	int i = 0;
	for (; i < count; i++){
		if (strcmp(c, contact[i].name) == 0){
			for (int j = i; j < count-1; j++){
				structcpy(&contact[j], &contact[j + 1]);
			}
			count--;
			printf("删除成功\n");
			break;
		}
	}
	if(count == i){
		printf("删除失败，查无此人");
	}
}
void find(struct AddressList *contact){
	char c[20];
	printf("请输入要查询的人的名字：");
	scanf("%s", &c);
	int i = 0;
	for (; i < count; i++){
		if (strcmp(c, contact[i].name) == 0){
			print(&contact[i]);
			break;
		}
	}
	if (count == i){
		printf("查无此人，请核对后重试\n");
	}
}
void change(struct AddressList *contact){
	char c[20];
	printf("请输入要修改的人的名字：");
	scanf("%s", &c);
	int i = 0;
	for (; i < count; i++){
		if (strcmp(c, contact[i].name) == 0){
			printf("请输入性别：");
			scanf("%s", contact[i].sex);
			printf("请输入年龄：");
			scanf("%d", &contact[i].age);
			printf("请输入电话：");
			scanf("%s", contact[i].telephone);
			printf("请输入住址：");
			scanf("%s", contact[i].address);
			printf("修改成功\n");
			break;
		}
	}
	if (count == i){
		printf("修改失败，查无此人\n");
	}
}
void show(struct AddressList *contact){
	for (int i = 0; i < count; i++){
		print(&contact[i]);
	}
}
void DelAll(struct AddressList *contact){
	count = 0;
	printf("删除完成\n");
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
	printf("排序完成\n");
}
void main(){
	int a;
	struct AddressList *contact = (struct AddressList *)malloc(num*sizeof(struct AddressList));
	while (1){
		if (count == num){
			num += 20;
			struct AddressList *contact2 = (struct AddressList *)malloc(num*sizeof(struct AddressList));
			for (int i = 0; i < count; i++){
				structcpy(&contact2[i], &contact[i]);
			}
			contact = (struct AddressList *)malloc(contact, num*sizeof(struct AddressList));
			for (int i = 0; i < count; i++){
				structcpy(&contact[i], &contact2[i]);
			}
		}
		system("cls");
		printf("菜单：\n");
		printf("1.添加联系人信息\n2.删除指定联系人信息\n3.查找指定联系人信息\n4.修改指定联系人信息\n5.显示所有联系人信息\n6.清空所有联系人\n7.以名字排序所有联系人\n");
		printf("请输入你的选项：");
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
		default:
			break;
		}
		system("pause");
	}
}