//Form.c
#include "Form.h"
#include "addressbook.h"
#include <stdio.h>
#include <string.h>

//�ڷ��� ����

#pragma warning(disable:4996)
//�Լ�����

	
//�Լ�����
	int main(int argc, char* argv[]) {
		AddressBook addressBook = { {{"","","",""},{"","","",""},{"","","",""},{"","","",""},{"","","",""},{"","","",""}},MAX,0 };
		int menu;

		Load(&addressBook);
		DisplayMenu();
		rewind(stdin); scanf("%d", &menu);
		while (menu != 0) {
			switch (menu) {
			case 1: FormForRecording(&addressBook);
				break;

			case 2: FormForFinding(&addressBook);
				break;
			
			case 3: FormForCorrecting(&addressBook);
				break;

			case 4: FormForErasing(&addressBook);
				break;

			case 5: FormForArranging(&addressBook);
				break;


			case 6: FormForViewAll(&addressBook);
				break;

			default: break;
			}
			DisplayMenu();
			rewind(stdin); scanf("%d", &menu);
		}
		Save(&addressBook);
		return 0;
	}

	void DisplayMenu() {
		system("cls");
		printf("\n\n\n\n\n\n");
		printf("\t\t\t    �ּҷ�version0.05\n");
		printf("\t\t\t    ===================\n");
		printf("\t\t\t    [1] �����ϱ�\n");
		printf("\t\t\t    [2] ã    ��\n");
		printf("\t\t\t    [3] �� ġ ��\n");
		printf("\t\t\t    [4] �� �� ��\n");
		printf("\t\t\t    [5] �����ϱ�\n");
		printf("\t\t\t    [6] ��ü����\n");
		printf("\t\t\t    [0] �� �� ��\n");
		printf("\t\t\t    -------------------\n");
		printf("\t\t\t    �޴��� �����Ͻʽÿ� ");
	}

	void FormForRecording(AddressBook* addressBook) {
		char name[11];
		char address[32];
		char telephoneNumber[12];
		char emailAddress[32];
		char recording;
		char going = 'Y';
		Long index;
		
		while (going == 'Y' || going == 'y') {
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\t�ּҷ�version0.05-�����ϱ�\n");
			printf("\t===================\n");
			printf("\t��      �� : "); rewind(stdin); scanf("%s", name);
			printf("\t��      �� : "); rewind(stdin); gets(address);
			printf("\t��ȭ  ��ȣ : "); rewind(stdin); scanf("%s", telephoneNumber);
			printf("\t�̸����ּ� : "); rewind(stdin); scanf("%s", emailAddress);
			printf("\t-------------------\n");
			printf("\t�����Ͻðڽ��ϱ�?(Yes/No) "); rewind(stdin); recording = getchar();
			
			if (recording == 'Y' || recording == 'y') {
				index = Record(addressBook, name, address, telephoneNumber, emailAddress);
				printf("\t==================================================================\n");
				printf("\t��ȣ    ����\t�ּ�\t\t\t��ȭ��ȣ\t�̸����ּ�\n");
				printf("\t------------------------------------------------------------------\n");
				printf("\t%d    %s\t%s\t\t\t%s\t%s\n",
					index + 1,
					addressBook->personals[index].name,
					addressBook->personals[index].address,
					addressBook->personals[index].telephoneNumber,
					addressBook->personals[index].emailAddress);
			}
			printf("\t==================================================================\n");
			printf("\t����Ͻðڽ��ϱ�?(Yes/No)"); rewind(stdin); going = getchar();
		}
	}

	void FormForViewAll(AddressBook* addressBook) {
		Long i = 0;
		Long j;

		while (i < addressBook->length) {
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\t�ּҷ�version0.05-��ü����\n");
			printf("\t==================================================================\n");
			printf("\t��ȣ    ����\t�ּ�\t\t\t��ȭ��ȣ\t�̸����ּ�\n");
			printf("\t------------------------------------------------------------------\n");

			j = 1;
			while (j <= 5 && i < addressBook->length) {
				printf("\t%d    %s\t%s\t\t\t%s\t%s\n",
					i + 1,
					addressBook->personals[i].name,
					addressBook->personals[i].address,
					addressBook->personals[i].telephoneNumber,
					addressBook->personals[i].emailAddress);
				i++;
				j++;
			}
			printf("\t==================================================================\n");
			printf("\t �ƹ�Ű�� �����ÿ�! "); rewind(stdin);  getchar();
		}
	}

	void FormForFinding(AddressBook* addressBook) {
		char name[11];
		Long indexes[MAX];
		Long count;
		Long i;
		char finding;
		char going = 'Y';
		while (going == 'Y' || going == 'y') {
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\t�ּҷ�version0.05-ã��\n");
			printf("\t==================================================================\n");
			printf("\t��      �� : "); rewind(stdin); scanf("%s", name);
			Find(addressBook, name, indexes, &count);
			printf("\t------------------------------------------------------------------\n");
			printf("\t��ȣ    ����\t�ּ�\t\t\t��ȭ��ȣ\t�̸����ּ�\n");
			printf("\t------------------------------------------------------------------\n");
			i = 0;
			while (i < count) {
				printf("\t%d    %s\t%s\t\t\t%s\t%s\n",
					i + 1,
					addressBook->personals[indexes[i]].name,
					addressBook->personals[indexes[i]].address,
					addressBook->personals[indexes[i]].telephoneNumber,
					addressBook->personals[indexes[i]].emailAddress);
				i++;
			}
			printf("\t==================================================================\n");
			printf("\t����Ͻðڽ��ϱ�?(Yes/No) "); rewind(stdin); going = getchar();
		}
	}
	
	void FormForCorrecting(AddressBook* addressBook) {
		char name[11];
		char address[32];
		char telephoneNumber[12];
		char emailAddress[32];
		char correcting;
		char going = 'Y';
		Long indexes[MAX];
		Long i;
		Long index;
		Long count;

		while (going == 'Y' || going == 'y') {
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\t�ּҷ�version0.05-��ġ��\n");
			printf("\t==================================================================\n");
			printf("\t��      �� : "); rewind(stdin); scanf("%s", name);
			Find(addressBook, name, indexes, &count);
			printf("\t------------------------------------------------------------------\n");
			printf("\t��ȣ    ����\t�ּ�\t\t\t��ȭ��ȣ\t�̸����ּ�\n");
			printf("\t------------------------------------------------------------------\n");
			i = 0;
			while (i < count) {
				printf("\t%d    %s\t%s\t\t\t%s\t%s\n",
					i + 1,
					addressBook->personals[indexes[i]].name,
					addressBook->personals[indexes[i]].address,
					addressBook->personals[indexes[i]].telephoneNumber,
					addressBook->personals[indexes[i]].emailAddress);
				i++;
			}
			if (count > 0) {
				printf("\t------------------------------------------------------------------\n");
				printf("\t��      ȣ : "); rewind(stdin); scanf("%d", &index);
				printf("\t��      �� : %s", addressBook->personals[indexes[index - 1]].address);
				rewind(stdin); gets(address);
				if (strcmp(address, "") == 0) {
					strcpy(address, addressBook->personals[indexes[index - 1]].address);
				}
				printf("\t��ȭ  ��ȣ : %s", addressBook->personals[indexes[index - 1]].telephoneNumber);
				rewind(stdin); gets(telephoneNumber);
				if (strcmp(telephoneNumber, "") == 0) {
					strcpy(telephoneNumber, addressBook->personals[indexes[index - 1]].telephoneNumber);
				}
				printf("\t�̸����ּ� : %s", addressBook->personals[indexes[index - 1]].emailAddress);
				rewind(stdin); gets(emailAddress);
				if (strcmp(emailAddress, "") == 0) {
					strcpy(emailAddress, addressBook->personals[indexes[index - 1]].emailAddress);
				}
				printf("\t------------------------------------------------------------------\n");
				printf("\t��ġ�ðڽ��ϱ�?(Yes/No) "); rewind(stdin); correcting = getchar();
				if (correcting == 'Y' || correcting == 'y') {
					index = Correct(addressBook, indexes[index - 1], address, telephoneNumber, emailAddress);
					printf("\t------------------------------------------------------------------\n");
					printf("\t��ȣ    ����\t�ּ�\t\t\t��ȭ��ȣ\t�̸����ּ�\n");
					printf("\t------------------------------------------------------------------\n");
					printf("\t%d    %s\t%s\t\t\t%s\t%s\n",
						index - 1,
						addressBook->personals[index].name,
						addressBook->personals[index].address,
						addressBook->personals[index].telephoneNumber,
						addressBook->personals[index].emailAddress);
				}
				printf("\t==================================================================\n");
				printf("\t����Ͻðڽ��ϱ�?(Yes/No) "); rewind(stdin); going = getchar();
			}
		}
	}

	void FormForErasing(AddressBook* addressBook) {
		Long indexes[MAX];
		Long index;
		Long i;
		Long count;
		char name[11];
		char erasing;
		char going = 'Y';
		while (going == 'Y' || going == 'y') {
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\t�ּҷ�version0.05-�����\n");
			printf("\t==================================================================\n");
			printf("\t��      �� : "); rewind(stdin); scanf("%s", name);
			Find(addressBook, name, indexes, &count);
			printf("\t------------------------------------------------------------------\n");
			printf("\t��ȣ    ����\t�ּ�\t\t\t��ȭ��ȣ\t�̸����ּ�\n");
			printf("\t------------------------------------------------------------------\n");
			i = 0;
			while (i < count) {
				printf("\t%d    %s\t%s\t\t\t%s\t%s\n",
					i + 1,
					addressBook->personals[indexes[i]].name,
					addressBook->personals[indexes[i]].address,
					addressBook->personals[indexes[i]].telephoneNumber,
					addressBook->personals[indexes[i]].emailAddress);
				i++;
			}
			if (count > 0) {
				printf("\t------------------------------------------------------------------\n");
				printf("\t��      ȣ : "); rewind(stdin); scanf("%d", &index);
				printf("\t------------------------------------------------------------------\n");
				printf("\t��ȣ    ����\t�ּ�\t\t\t��ȭ��ȣ\t�̸����ּ�\n");
				printf("\t------------------------------------------------------------------\n");
				printf("\t%d    %s\t%s\t\t\t%s\t%s\n",
					indexes[index - 1] + 1,
					addressBook->personals[indexes[index - 1]].name,
					addressBook->personals[indexes[index - 1]].address,
					addressBook->personals[indexes[index - 1]].telephoneNumber,
					addressBook->personals[indexes[index - 1]].emailAddress);
				printf("\t------------------------------------------------------------------\n");
				printf("\t����ðڽ��ϱ�?(Yes/No) "); rewind(stdin); erasing = getchar();
				if (erasing == 'Y' || erasing == 'y') {
					index = Erase(addressBook, indexes[index - 1]);
					if (index == -1) {
						printf("\t==================================================================\n");
						printf("\t���������ϴ�! \n");
					}
				}
			}
			printf("\t==================================================================\n");
			printf("\t����Ͻðڽ��ϱ�?(Yes/No) "); rewind(stdin); going = getchar();
		}
	}

	void FormForArranging(AddressBook* addressBook){
	Long i = 0;
	Long j;

	Arrange(addressBook);
	while (i < addressBook->length) {
		system( "cls" );
		printf("\n\n\n\n\n\n\n\n");
		printf("\t�ּҷ�version0.05-�����ϱ�\n");
		printf("\t==================================================================\n");
		printf("\t��ȣ    ����\t�ּ�\t\t\t��ȭ��ȣ\t�̸����ּ�\n");
		printf("\t------------------------------------------------------------------\n");

		j = 1;
		while (j <= 5 && i < addressBook->length) {
			printf("\t%d    %s\t%s\t\t\t%s\t%s\n",
				i + 1,
				addressBook->personals[i].name,
				addressBook->personals[i].address,
				addressBook->personals[i].telephoneNumber,
				addressBook->personals[i].emailAddress);
			i++;
			j++;
		}
		printf("\t==================================================================\n");
		printf("\t �ƹ�Ű�� �����ÿ�! "); rewind(stdin);  getchar();
	}
	}