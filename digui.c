void main()

{ int a[6]��{10,20,30,40,50,60},i;

  invert(a,0,5);

  for(i=0;i<6;i++) printf("%d,,a��i��);

  printf("\n");

}

invert(int s�� ��,int i,int j)

{ int  t;

  if(i<j)

  { invert(s,i+1,j-1);

    t=s[i];s[i]=s[j];s[j]=t; }

 }
