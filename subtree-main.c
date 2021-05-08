#include "libfdr/jrb.h"

#include <stdio.h>

int main()
{
	JRB r = make_jrb();
	FILE *inp = fopen("input.txt","r");
	int n;
	fscanf(inp, "%d",&n);
	for(int i=0;i<n;i++)
	{
		int key,m;
		fscanf(inp,"%d%d",&key,&m);
		JRB sub=make_jrb();
		jrb_insert_int(r,key,(Jval){.v=sub});
		for(int j=0;j<m;j++)
		{
			int key;
			fscanf(inp,"%d",&key);
			jrb_insert_int(sub,key,(Jval){.v=NULL});
		}
	}
	int v1,v2;
	scanf("%d %d",&v1,&v2);
	JRB node = jrb_find_int(r,v1);
	if(node)
	{
		JRB sub=node->val.v;
		node = jrb_find_int(sub,v2);
		if(node)
		{
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}else{
		printf("NO\n");
	}
}