//17. Напишите программу, в которой создается три одномерных числовых массива 
//одинакового размера.Первые два массива заполняются случайными числами.Третий массив
//заполняется так : сравниваются элементы с такими же индексами в первом и втором массиве и в
//третий массив на такую же позицию записывается большее(или меньшее) из сравниваемых
//значений.

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
	const int array_size = 10;
	int* a = new int[array_size];
	int* b = new int[array_size];
	int* c = new int[array_size];

	for (size_t i = 0; i < array_size; i++)	{
		a[i] = rand() % 50 + 10;
		b[i] = rand() % 50 + 10;
		c[i] = 0;
	}


	for (size_t i = 0; i < array_size; i++)
		cout << a[i] << ' ';
	cout << endl;

	for (size_t i = 0; i < array_size; i++)
		cout << b[i] << ' ';
	cout << endl;


	_asm {
		mov eax, a
		mov ebx, b
		mov edi, c
		mov ecx, array_size
		comparation_loop:
			mov edx, [eax]
			mov esi, [ebx]
			cmp edx, esi
			jg greater_than
				mov [edi], esi
				jmp to_next_elems
			greater_than:
				mov [edi], edx
		to_next_elems:
			add eax, 4
			add ebx, 4
			add edi, 4
		loop comparation_loop
	};

	cout << endl;

	for (size_t i = 0; i < array_size; i++)
		cout << c[i] << ' ';
	cout << endl;

}
