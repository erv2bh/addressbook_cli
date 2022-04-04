/*
���ϸ�: AddressBook.c
���: �ּҷϿ� ����, �ּ�, ��ȭ��ȣ, �̸����� �����ϰ� ã�� ��ġ�� ����� �����Ѵ�
�ۼ���: �����
�ۼ�����: 2021/04/09
*/

#include "addressbook.h"
#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

//�Լ�����
#if 0
int main(int argc, char *argv[]){
	AddressBook addressBook = {{{"","","",""},{"","","",""},{"","","",""},{"","","",""},{"","","",""},{"","","",""}},MAX,0};
	Long capacity;
	Long count;
	Long index;
	Long indexes[MAX];
	Long i;

	count = Load(&addressBook);
	i = 0;
	while (i < count) {
		printf("%s %s %s %s\n", addressBook.personals[i].name, addressBook.personals[i].address, addressBook.personals[i].telephoneNumber, addressBook.personals[i].emailAddress);
		i++;
	}
#if 0
	index = Record(&addressBook,(char *) "ȫ�浿",(char *) "����� ���ʱ�",(char *) "025389424",(char*) "hong@");
	printf("%s%s%s%s\n", addressBook.personals[index].name, addressBook.personals[index].address, addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
	index = Record(&addressBook,(char*) "��浿",(char*) "������ �߱�",(char*) "025189424",(char*) "go@");
	printf("%s%s%s%s\n", addressBook.personals[index].name, addressBook.personals[index].address, addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
	index = Record(&addressBook,(char*) "�ڱ浿",(char*) "�뱸��",(char*) "025289424",(char*) "park@");
	printf("%s%s%s%s\n", addressBook.personals[index].name, addressBook.personals[index].address, addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
	index = Record(&addressBook,(char*) "Ȳ�浿",(char*) "���ֽ�",(char*) "025489424",(char*) "hwang@");
	printf("%s%s%s%s\n", addressBook.personals[index].name, addressBook.personals[index].address, addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
	index = Record(&addressBook,(char*) "���浿",(char*) "�λ��",(char*) "025689424",(char*) "jo@");
	printf("%s%s%s%s\n", addressBook.personals[index].name, addressBook.personals[index].address, addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
	
	Find(&addressBook,(char*) "ȫ�浿", indexes, &count);
	i = 0;
	while (i < count) {
		printf("%s%s%s%s\n", addressBook.personals[indexes[i]].name, addressBook.personals[indexes[i]].address, addressBook.personals[indexes[i]].telephoneNumber, addressBook.personals[indexes[i]].emailAddress);
		i++;
	}
	
	index = Correct(&addressBook, 2,(char*) "�Ⱦ��",(char*) "025989424",(char*) "kim@");
	printf("%s%s%s%s\n", addressBook.personals[index].name, addressBook.personals[index].address, addressBook.personals[index].telephoneNumber, addressBook.personals[index].emailAddress);
	
	index = Erase(&addressBook, 3);
	if (index == -1) {
		printf("���������ϴ�\n");
	}
	
	Arrange(&addressBook);
	i = 0;
	while (i < addressBook.length) {
		printf("%s%s%s%s\n", addressBook.personals[i].name, addressBook.personals[i].address, addressBook.personals[i].telephoneNumber, addressBook.personals[i].emailAddress);
		i++;
	}

	Save(&addressBook);
#endif
	return 0;
}
#endif

/*
�Լ��̸�: Record
���: �̸�, �ּ�, ��ȭ��ȣ, �̸����ּҸ� �����Ѵ�
�Է�: �̸�, �ּ�, ��ȭ��ȣ, �̸����ּ�
���: ��ġ
*/

Long Record(AddressBook* addressBook, char(*name), char(*address), char(*telephoneNumber), char(*emailAddress)){
Long index = -1;
Long i = 0;

while(i < addressBook->capacity && strcmp(addressBook->personals[i].name, "") != 0){
	i++;
}
if (i < addressBook->capacity) {
	index = i;
	strcpy(addressBook->personals[index].name, name);
	strcpy(addressBook->personals[index].address, address);
	strcpy(addressBook->personals[index].telephoneNumber, telephoneNumber);
	strcpy(addressBook->personals[index].emailAddress, emailAddress);
	addressBook->length = addressBook->length + 1;
}
return index;
}

/*
�Լ��̸�: Find
���: �̸��� �Է¹޾� ��ġ��, ������ ���Ѵ�
�Է�: �̸�
���: ��ġ, ����
*/

void Find(AddressBook* addressBook, char(*name), Long(*indexes), Long* count){
Long i = 0;
	Long j = 0;
	*count = 0;
	while (i < addressBook->length) {
		if (strcmp(addressBook->personals[i].name, name) == 0) {
			indexes[j] = i;
			j++;
			(*count)++;
		}
		i++;
	}
}

/*
�Լ��̸�: Correct
���: ��ġ, �ּ�, ��ȭ��ȣ, �̸����ּҸ� �Է¹޾� ��ģ��
�Է�: ��ġ, �ּ�, ��ȭ��ȣ, �̸����ּ�
���: ��ġ
*/

Long Correct(AddressBook* addressBook, Long index, char(*address), char(*telephoneNumber), char(*emailAddress)) {
	strcpy(addressBook->personals[index].address, address);
	strcpy(addressBook->personals[index].telephoneNumber, telephoneNumber);
	strcpy(addressBook->personals[index].emailAddress, emailAddress);
	return index;
}

/*
�Լ��̸�: Erase
���: ��ġ�� �Է¹޾� ����Ѵ�
�Է�: ��ġ
���: ��ġ
*/

Long Erase(AddressBook* addressBook, Long index) {
	strcpy(addressBook->personals[index].name, "=");
	index = -1;
	return index;
}

/*
�Լ��̸�: Arrange
���: �̸����� ������������ �����Ѵ�
�Է�: ����
���: ����
*/

void Arrange(AddressBook* addressBook) {
	Long i = 0;
	Long j;
	Long count = 0;
	Long position;
	Personal personal;
	while (i < addressBook->length - 1) {
		position = i;
		j = i + 1;
		while (j < addressBook->length) {
			if (strcmp(addressBook->personals[j].name,addressBook->personals[position].name)>0) {
				position = j;
			}
			j++;
		}
		personal = addressBook->personals[position];
		addressBook->personals[position] = addressBook->personals[i];
		addressBook->personals[i] = personal;
		i++;
	}
	i = 0;
	while (i < addressBook->length && strcmp(addressBook->personals[i].name, "=") != 0) {
		count++;
		i++;
	}
	i = 1;
	while (i < count) {
		personal = addressBook->personals[i];
		j = i - 1;
		while (j >= 0 && strcmp(addressBook->personals[j].name, personal.name) > 0) {
			addressBook->personals[j + 1] = addressBook->personals[j];
			j--;
		}
		addressBook->personals[j + 1] = personal;
		i++;
	}
}

Long Load(AddressBook* addressBook) {
	Personal personal;
	Long i = 0;

	FILE* file = fopen("addressBook.dat", "rb");
	size_t flag;
	if (file != NULL) {
		flag = fread(&personal, sizeof(Personal), 1, file);
		while (!feof(file) && flag != 0) {
			addressBook->personals[i] = personal;
			i++;
			addressBook->length = addressBook->length + 1;
			flag = fread(&personal, sizeof(Personal), 1, file);
		}
		fclose(file);
	}
	return addressBook->length;
}

Long Save(AddressBook* addressBook) {
	Long i = 0;
	FILE* file = fopen("addressBook.dat", "wb");
	if (file != NULL) {
		while (i < addressBook->length) {
			fwrite(addressBook->personals + i, sizeof(Personal), 1, file);
			i++;
		}
		fclose(file);
	}
	return addressBook->length;
}