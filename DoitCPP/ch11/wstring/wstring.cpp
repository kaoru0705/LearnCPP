#include <iostream>
#include <string>

int main() {
	// setlocale �Լ��� ����Ͽ� ���α׷��� ������(locale)�� ����
	// LC_ALL�� '��� ������' �������� ������ �ǹ���
	setlocale(LC_ALL, "");

	// wstring�� ����Ͽ� �����ڵ� ���ڿ��� �ʱ�ȭ
	// L ���λ縦 �ٿ� �����ڵ� ���ڿ����� ��Ÿ��
	std::wstring korString = L"�ȳ��ϼ���, C++ ����";

	// wcout�� ����Ͽ� �����ڵ� ���ڿ��� ���
	// wcout�� �����ڵ� ���ڿ��� ����ϱ� ���� wide character ��� ��Ʈ��
	std::wcout << korString << std::endl;

	return 0;
}