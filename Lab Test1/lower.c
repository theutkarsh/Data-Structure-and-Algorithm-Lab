#include "node.h"
BOOL IsLower_GM(int id1, int id2)
{
int gp1=id1%10000;
int gp2=id2%10000;
 id1=id1/10000;
 id2=id2/10000;
 if(gp1<gp2)
 return 1;
 else if(id1%1000 <id2%1000 && gp1==gp2)
  {
  	return 1;
 	}
 else return 0;
}
