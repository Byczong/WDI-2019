#include<iostream>
#include<algorithm>
using namespace std;

const int N = 100;

struct node
{
	int w;
	node* next;
};

int dlugosc(node* s, node* lente)
{
	int licz = 0;
	while (s != lente)
	{
		licz++;
		s = s->next;
	}
	return licz;
}

int nodes_before_loop(node* s)
{
	int licznik = N;
	node* lente = s;
	node* rapide = s;
	if(rapide->next != nullptr)
		do
		{
			lente = lente->next;
			rapide = rapide->next->next;
		} while (rapide != nullptr and rapide->next != nullptr and lente != nullptr and lente != rapide);
	// lente - element w cyklu
	if(lente != nullptr)
		do
		{
			licznik = min(licznik, dlugosc(s, lente));
			lente = lente->next;
		} while (lente != rapide and lente != nullptr);

	return licznik;
}

int main()
{
	node* a = new node;
	node* b = new node;
	node* c = new node;
	node* d = new node;
	node* e = new node;
	node* f = new node;

	a->w = 1;
	b->w = 2;
	c->w = 3;
	d->w = 4;
	e->w = 5;
	f->w = 6;

	a->next = b;
	b->next = c;
	c->next = d;
	d->next = e;
	e->next = f;
	f->next = a;

	cout << nodes_before_loop(a);
}
