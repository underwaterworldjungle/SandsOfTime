/* Sands of Time by Jeremy Bird (github.com/underwaterworldjungle) 2022 */

#include <stdio.h>
#include <unistd.h>
#include <conio.h>
#include <stdlib.h>

int main(void)
{
	// TITLE SCREEN
	
	printf("\n       )\\.--.    /`-.   )\\  )\\    )\\.-.  )\\.--.\n      (   ._.' ,' _  \\ (  \\, /  ,'     )(   ._.'\n       `-.`.  (  '-' (  ) \\ (  (  .-, (  `-.`.\n      ,_ (  \\  )   _  )( ( \\ \\  ) '._\\ ),_ (  \\\n     (  '.)  )(  ,' ) \\ `.)/  )(  ,   ((  '.)  )\n   .-./(_)`-.--./    .-,.-.,-..'(/ )\\.' )\\_)\\.---.\n ,'     )) ,-._(     ) ,, ,. (\\  )(  ',/ /(   ,-._(\n(  .-, ( \\ `-._      \\( |(  )/) (  )    (  \\  '-,\n ) '._\\ ) ) ,_(         ) \\   \\  )(  \\(\\ \\  ) ,-`\n(  ,   ( (  \\           \\ (    ) \\ `.) /  )(  ``-.\n )/ ._.'  ).'            )/     )/     '.(  )..-.(\n");
	sleep(2);
	printf("\n\nSANDS OF TIME  v0.02\n");
	sleep(1);
	printf("A timeless classic by Jeremy Bird\n\n");
	sleep(2);
	printf("PRESS [ENTER] TO START");
	while(getchar()!='\n');
	
	// SETTING
	
	system("cls");
	printf("\a\nYou are a sojourner on the SANDS OF TIME.\n");
	sleep (2);

	// AGING
	
	printf("\nHow long will you age?\n");
	
	unsigned int daysgoal;
	unsigned int hoursgoal;
	unsigned int minsgoal;
	unsigned int secsgoal;
	
	unsigned int days=0;
	unsigned int hours=0;
	unsigned int mins=0;
	unsigned int secs=0;
	
	printf("\nDays (0-99):\t");
	scanf("%i",&daysgoal);
	if(daysgoal>99){daysgoal=99;}
	printf("\nHours (0-23):\t");
	scanf("%i",&hoursgoal);
	if(hoursgoal>23){hoursgoal=23;}
	printf("\nMinutes (0-59):\t");
	scanf("%i",&minsgoal);
	if(minsgoal>59){minsgoal=59;}
	printf("\nSeconds (0-59):\t");
	scanf("%i",&secsgoal);
	if(secsgoal>59){secsgoal=59;}
	
	system("cls");
	printf("\nYou will age;\tDays: %i \tHours: %i \tMinutes: %i \tSeconds: %i ",daysgoal,hoursgoal,minsgoal,secsgoal);
	printf("\n\nAging...\t\t(Press [0 - 9] to manipulate the flow of sand; # [real seconds] per grain of sand.)\n\n");
	
	int timepass=0;
	int timescale=1;
	
	while(!(timepass==1))
	{
		if(kbhit()){timescale=getch()-48;}
		if(timescale<0){timescale=1;}
		if(timescale>9){timescale=1;}
		
		if((secs==secsgoal && mins==minsgoal && hours==hoursgoal && days==daysgoal))
		{timepass=1;}
		
		if(timescale>0){printf("\a");}
		printf("\rYou have aged;\tDays: %i \tHours: %i \tMinutes: %i \tSeconds: %i \tFlow: %i real second(s) per grain of sand",days,hours,mins,secs,timescale);
		sleep(timescale);
		
		if((secs==59 && mins!=59))
		{mins=mins+1;secs=0;}
		else if(!(secs==59))
		{secs=secs+1;}
		else if((mins==59 && hours!=23 && secs==59))
		{hours=hours+1;mins=0;secs=0;}
		else if((hours==23 && mins==59 && secs==59))
		{days=days+1;hours=0;mins=0;secs=0;}
	}
	
	system("cls");
	printf("\a\nYou have aged %i days, %i hours, %i minutes and %i seconds sojourning the SANDS OF TIME.\n");
	sleep(2);
	
	//ENDING
	
	printf("\nPress any key to quit.");
	getch();
	
	return 0;
}
