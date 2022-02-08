int GameOver(){

}



void ShieldControls(int shipDamageArray[9], int *currentEnergy, int *currentShield){
    if (shipDamageArray[7] < 0){
        printf("SHIELD CONTROL INOPERABLE \n");
        return;//GOTO 1990
    }
    printf("ENERGY AVAILABLE = %d\n", *currentEnergy + *currentShield);
    int energyInput;
    printf("NUMBER OF UNITS TO SHEILDS?");
    scanf("%d", &energyInput);
    printf("\n");

    if ((energyInput < 0) || (*currentShield == *energyInput)){
        printf("<SHEILDS UNCHANGED>\n");
        return; //GOTO 1990
    }

    if (!(energyInput <= *currentEnergy + *currentShield)){ //IF energyInput<=currentEnergy+currentShield THEN 5630
//5630
        currentEnergy = *currentEnergy + *currentShield - energyInput;
        currentShield = energyInput;
        printf("DEFLECTOR CONTROL ROOM REPORT: \n");
        printf(" 'SHIELDS NOW AT UNITS PER YOUR COMMAND.' \n");
        return;//GOTO 1990
    }
//5600
    printf("SHIELD CONTROL REPORTS  'THIS IS NOT THE FEDERATION TREASURY.'");
    printf("<SHIELDS UNCHANGED>");
	return;//GOTO 1990
}

void StatusReport(int starBaseTotal,int totalKlingons,int currentStardate,int daysRemaining,int startStardate,char sPluralize){
    printf("   STATUS REPORT : \n");
    strcpy(sPluralize,"");
    if (totalKlingons > 1){
        strcpy(sPluralize,"S");
    }

    printf("KLINGON %c LEFT : %d\n", sPluralize, totalKlingons);
    printf("MISSION MUST BE COMPLETED IN %d STARDATES \n", (int)((currentStardate+daysRemaining-startStardate)*10));

    strcpy(sPluralize,"S");
    if (starBaseTotal < 2){
        strcpy(sPluralize," ");
        if (starBaseTotal < 1){
            bool gotoSwitch8010 = 1;//GOTO 8010
        }
    }

    if (gotoSwitch8010!=1){
        printf(" THE FEDERATION IS MAINTAINING %d STARBASE %c IN THE GALAXY \n", starBaseTotal, sPluralize);
        return;//GOTO 5690
    }
    printf("YOUR STUPIDITY HAS LEFT YOU ON YOUR OWN IN\n");
    printf("THE GALAXY -- YOU HAVE NO STARBASES LEFT!\n");
    return;//GOTO 5690
}
