#include"avl.h"

int main(void)
{
	Node* root=create(9);
	add(root,5);
	add(root,4);
	add(root,120);
	add(root,8);
	add(root,6);
		add(root,15);
	add(root,14);
	add(root,20);
	add(root,18);
	add(root,63);
		add(root,12223);
			add(root,-326);
	printf("\n%d\n",find(root,374));
		print(root);
printf("\n");
	deleten(root,63);
	print (root);
	printf("\n");

}
