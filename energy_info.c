#include <stdio.h>
int main(){
  int level[]={75,50,25,10,0};
  char* icons[]={"󱊣","󱊢","󱊡","󰂎","󰂃"};
  FILE *file;char buffer[8];

  file=popen("acpi -b | awk '{print $4}' | tr -d '%,'", "r");
  fgets(buffer, 8, file);

  unsigned int current=0,i=0;
  for(i=0;buffer[i]!='\n';i++)
    current=current*10+buffer[i]-'0';
  if(current==100)return 0;
  for(i=0;i<sizeof(level)/sizeof(int);i++)
    if(current>level[i])break;

  printf("%d%s",current,icons[i]);
  return 0;
}
