#include <stdio.h>
enum State{discharge,charge};
int main(){
  int level[]={75,50,25,10,0};
  char* dischargeIcons[]={"󱊣","󱊢","󱊡","󰂎","󰂃"};
  char* chargeIcons[]={"󱊦","󱊥","󱊤","󰢟","󰢟"};
  char** icons[]={dischargeIcons,chargeIcons};
  FILE *file;char buffer[8];
  unsigned int current=0,i=0,state=discharge;

  file=popen("acpi -b | awk '{print $4}{print $3}' | tr -d '%,'", "r");
  fgets(buffer, 8, file);

  for(i=0;buffer[i]!='\n';i++)
    current=current*10+buffer[i]-'0';

  fgets(buffer, 8, file);
  if(buffer[0]=='F')return 0;

  if(buffer[0]=='C')state=charge;
  for(i=0;i<sizeof(level)/sizeof(int);i++)
    if(current>level[i])break;

  printf("%d%s |",current,icons[state][i]);
  return 0;
}
