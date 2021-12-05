#define	_CRT_SECURE_NO_WARNINGS 1

#include<iostream>
using namespace std;
typedef int elemtype;
typedef int keytype;
typedef struct {
	elemtype* elem;//����
	int length;//˳�����
}SSTable;
void CreateSSTable(SSTable& ST, int n) {
	ST.elem = (elemtype*)malloc(n * sizeof(elemtype));
	if (!ST.elem) {
		cout << "�������ʧ��" << endl;
		exit(-1);
	}
	ST.length = n;
	cout << "��������Ҫ����˳����Ԫ�أ�";
	for (int i = 1; i <= n; i++) {
		cin >> ST.elem[i];
	}
}

//˳�����
int Search_Seq(SSTable ST, keytype key) {
	//��˳����в���ֵΪkey������Ԫ�أ����ҵ��������±꣬���򷵻�0-������
	int i;
	ST.elem[0] = key;//������
	for (i = ST.length; ST.elem[i] != key; i--);
	return i;
}
//�۰����-�����������
int Search_Bin(SSTable ST, keytype key) {
	int low = 1, high = ST.length, mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (ST.elem[mid] < key)
			low = mid + 1;
		else if (ST.elem[mid] > key)
			high = mid - 1;
		else
			return mid;
	}
	return 0;
}

int main() {
	SSTable ST;
	int n, input;
	keytype key;
	cout << "**************************************************************" << endl;
	cout << "  1.˳�����          2.�۰���ң������        3.�˳�����  " << endl;
	cout << "**************************************************************" << endl;
	while (1) {
		cout << "��������Ҫ���еĲ�����";
		cin >> input;
		switch (input) {
		case 1: {
			cout << "������������˳���ĳ��ȣ�";
			cin >> n;
			CreateSSTable(ST, n);
			cout << "��������Ҫ���ҵ�ֵ��";
			cin >> key;
			cout<<key<<"����λ��Ϊ����Ϊ0����û�ҵ�����" << Search_Seq(ST, key) << endl;
			break;
		}
		case 2: {
			cout << "������������˳���������ĳ��ȣ�";
			cin >> n;
			CreateSSTable(ST, n);
			cout << "��������Ҫ���ҵ�ֵ��";
			cin >> key;
			cout<<key<<"����λ��Ϊ����Ϊ0����û�ҵ�����" << Search_Bin(ST, key) << endl;
			break;
		}
		case 3: {
			cout << "�˳�����" << endl;
			exit(0);
		}
		default: {
			cout << "�����������������" << endl;
			break;
		}
		}
	}
}
