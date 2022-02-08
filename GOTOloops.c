//conditional 1990  will also be void goto1990()
do {
	//1990
	if ((currentEnergy > 10) || (shipDamageArray ==0){
		//2060
		printf("COMMAND: \n);
		scanf("%c", tempObject);
		for (int i = 1, i <= 9, i++){
			if(parseLEFT(tempObject, 3)) != (parseMID(tempObject, 3*i-2,3)){
			//2160
			break;
			}
		}
		printf("ENTER ONE OF THE FOLLOWING: n");
		printf("  NAV  (TO SET COURSE)\n");
		printf("  SRS  (FOR SHORT RANGE SENSOR SCAN)\n");
		printf("  LRS  (FOR LONG RANGE SENSOR SCAN)\n");
		printf("  PHA  (TO FIRE PHASERS)\n");
		printf("  TOR  (TO FIRE PHOTON TORPEDOES)\n");
		printf("  SHE  (TO RAISE OR LOWER SHIELDS)\n");
		printf("  DAM  (FOR DAMAGE CONTROL REPORTS)\n");
		printf("  COM  (TO CALL ON LIBRARY-COMPUTER)\n");
		printf("  XXX  (TO RESIGN YOUR COMMAND) \n");
		goto1990();//GOTO 1990
	}
	else {
		printf("** FATAL ERROR **   YOU'VE JUST STRANDED YOUR SHIP IN \n SPACE");
		printf("\n YOU HAVE INSUFFEICENT MANEUVERING ENERGY\n");
		printf("AND SHIELD CONTROL \n IS PRESENTLY INCAPABLE OF CROSS");
		printf("-CIRCUITING TO ENGINE ROOM!!");
	
		//from line 6220
		printf("IT IS STARDATE %d", startStarDate);
	
		//at GOTO 6270		
		printf("THERE WERE %d KLINGON BATTLE CRUISERS LEFT AT\n");
		printf("THE END OF YOUR MISSION. \n \n");
		if (starBaseTotal = 0){
			//from line 6360
		}
		else{
			printf("THE FEDERATION IS IN NEED OF A NEW STARSHIP COMMANDER\n");
			printf("FOR A SIMILAR MISSION -- IF THERE IS A VOLUNTEER,\n");
			printf("LET HIM STEP FORWARD AND ENTER 'AYE'");
			scanf("%s", &tempObject);
			if ((tempObject == 'AYE') || (tempObject == 'aye') || (tempObject == 'Aye')){
				//go to beginning of game
			} 
			else{
				exit(0);
			}
		}	
	}	
} while (currentShield+currentEnergy)<=10);


// Conditional goto 1200
do {
	//1200
	startKlingons = totalKlingons;
	if (starBaseTotal != 1){
		sPluralize = 'S';
		verbPluralize = 'ARE';
	}
	printf("YOUR ORDERS ARE AS FOLLOWS: \n");
	printf("DESTROY THE %d KLINGONS WARSHIPS WHICH HAVE INVADED\n", totalKlingons);
	printf("THE GALAXY BEFORE THEY CAN ATTACK FEDERATION HEADQUARTERS\n");
	printf("ON STARDATE %d. THIS GIVES YOU %d DAYS. THERE %c", currentStardate + totalStardate, totalStardate, verbPluralize);
	printf("\n %d STARBASE%c IN THE GALAXY FOR RESUPPLYING YOUR SHIP. \n", starBaseTotal, sPluralize);
	printf("n HIT ANY KEY EXCEPT REUTURN WHEN READY TO ACCEPT COMMAND.");
	
}while (starBaseTotal != 0);


//GOTO 5690 is found in lines 7890 and 7990 so it is best to create a functio n for these
void goto5690(){ 
do(
		if (shipDamageArray[6] >= 0){
		//starting from 5910
		printf("\nDEVICE             STATE OF REPAIR");
		for (int repairState = 1, repairState <= 8, repairState++){
			printDeviceName(repairState); //gosub 8790
			printf("%s %c %d", shipPartName, parseLEFT(spacingSpace, 25-strlen(shipPartName)), shipDamageArray[repairState]*100*0.1); 
		}
		
		if (starBaseShieldTf !=0){
			//starting from 5720
			repairTime = 0;
			for (int i = 0, i <= 8, i++){
				if (shipDamageArray[i] < 0){
				//5720
					repairTime = repairTime + 0.1;
				}	
			}
			
		}
		if (repairTime = 0){
			goto1990();
		}
		
		printf("\n");
		repairTime = repairTime + quadrantDamageMod;
		if (repairTime >= 1){
			repairTime = 0.9;
		}
		
		printf("TECHNICIANS STANDING BY TO EFFECT REPAIRS TO YOUR SHIP;");
		printf("\n ESTIMATED TIME TO REPAIR : %d STARDATES\n", 0.1*(int)100*repairTime);
		printf("WILL YOU AUTHORIZE THE REPAIR ORDER (Y/N)? ");
		scanf("%c", &tempObject);
		
		if ((tempObject == 'Y') || (tempObject == 'y')){
			goto1990();
		}
		
		for (int i = 1, i <= 8, i++){
			if (shipDamageArray[i] < 0){
				shipDamageArray[i] = 0;
			}
		}
		startStardate = startStardate + repairTime+ 0.1;
		print("\n"); 
	}	
	else {
	goto1990();
	} ) while (shipDamageArray[6] >= 0);
	
}
