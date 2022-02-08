#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ------ Variable Declaration ------*/
int libInput, tempTorpedoInitialCoord2;     /* A */
int localStarBases, starBaseSector1, starBaseSector2, starBaseTotal;    /* B3, B4, B5, B9 */
int courseDirectionInput, tempTorpedoInitialCoord1;     /* C1 */
int starBaseShieldTf, queueDamageReportTf, repairTime, quadrantDamageMod, warpSpeedDamageMod; //D0, D1, D3, D4, D6
int currentEnergy, maxEnergy;       /* E, E0 */
int noNumberNamesTf;       /* G5 */
int enemyHit, multiTargetMod, libMenu;      /* H, H1, H8 */
int i, j, l;         /* index */
int printAdvance;       /* J0 */
int localKlingons, startKlingons, totalKlingons;        /*K3, K7, K9 */
int energyToWarp;       /* N */
int currentTorpedos, maxTorpedos;       /* P, P0 */
int quadrant1, quadrant2, tempQuad1, tempQuad2;        /* Q1, Q2, Q4, Q5 */
//random variables R1 R2 defined within main when instance is mentioned in BASIC Code
int currentShield, sector1, sector2, localStars, objectLocation, klingonShieldMod;      /* S, S1, S2, S3, S8, S9 */
int startStardate, currentStardate, travelTime, daysRemaining;      /* T, T0, T8, T9 */
int warpInput, tempTorpedoFinalCoord1;       /* W1 */
int tempTorpedoFinalCoord2, positionMod1, positionMod2, torpedoTracker1, outOfBoundsTf;     /* X X1, X2, X3, X5 */
int torpedoTracker2;    /* Y3 */
// x and y variables will be mentioned inline depending on BASIC Code
int tempObjectPos1, tempObjectPos2, mapComparisonTf, quadrantName1, quadrantName2;      /* Z1, Z2, Z3, Z4, Z5*/

/* ------ Array Declaration ------*/
int navArray[][];       /* C( i, j ) array to make the rotary navigation work correctly*/
int shipDamageArray[];      /* D( i ) array stores whether sections of ship are damaged or not*/
int galaxyInfo[][];     /* G( i, j ) array stores number of klingon, bases and stars in given quadrant*/
int klingonData[][];    /* K( i, j ) array stores kligon ship data */
int scannerArray[];    /* N( i ) array to do with long range scanner code*/
int tempInfo[][];        /* Z( i, j) array secondary quadrant information */

/* ------ Character Declaration ------*/
char tempObject, commandDisplay;          /* A$, A1$ */
char shipCondition;           /* C$ */
char shipPartName;           /* G2$ */
char spacingText;          /* O1$ */
char quadrantMap;          /* Q$ */
char sPluralize, verbPluralize;           /* X$, X0$ */
char spacingSpace;          /* Z$ */

int main()
{
//------ BLOCK 9 ------
//KLINGONS MOVE/FIRE ON MOVING STARSHIP
    int i;
    for (i = 1; i >= localKlingons; i++)
    {
        if (klingonData[i][3] = 0)
        {
            break;
        }
        tempObject = ' ';
        tempObjectPos1 = klingonData[i][1];
        tempObjectPos2 = klingonData[i][2];
        //function for line 8670
        //function for line 8590

        klingonData[i][1]= tempObjectPos1;
        klingonData[i][2] = tempObjectPos2;
        tempObject = '+K+';
        //gosub 8670 fuction for 8670
    }
    // line2700();

    for (i = 1; i <= 8; i++)
    {
        if (shipDamageArray(i)>=0)
        {
            //line 2880
        }
        shipDamageArray(i) = shipDamageArray(i)+warpSpeedDamageMod;
        if ((shipDamageArray(i) > - 0.1) && (shipDamageArray(i) < 0))
        {
            shipDamageArray(i) = -0.1;
            //GOTO 2880
        }
        if (shipDamageArray(i) < 0)
        {
            //line 2880
        }
        if (queueDamageReportTf != 1)
        {
            queueDamageReportTf = 1;
            printf("DAMAGE CONTROL REPORT: \n");
        }
        printf("\t\t\t\t\t\t\t\t"); //TAB
        R1 = i;
        //GOSUB 8790
        printf("%s: REPAIR COMPLETED\n", shipPartName);
    }
    if (rand(1) > 0.2)
    {
        //line 3070
    }
    R1 = //FNR(1)
        if rand(1) >= 0.6
    {
        //line 3000
    }

    shipDamageArray(R1) = shipDamageArray(R1) - (rand(1)*5)+1;
    printf("DAMAGE CONTROL REPORT: \n");
    //GOSUB 8790
    printf(" %s: DAMAGED\n", shipPartName);

    shipDamageArray(R1) = shipDamageArray(R1) - (rand(1)*3)+1;
    printf("DAMAGE CONTROL REPORT: \n");
    //GOSUB 8790
    printf("%s: STATE OF REPAIR IMPROVED\n", shipPartName);
    printf(" \n");


//----- BLOCK 10 -----
//BEGIN MOVING STARSHIP
    tempObject = ' ';
    tempObjectPos1 = (int) sector1;
    tempObjectPos2 = (int) sector2;
    //GOSUB 8670
    postionMod1 = navArray[courseDirectionInput][1] +((navArray[courseDirectionInput+1][1] -navArray[courseDirectionInput][1])*(courseDirectionInput-(int)courseDirectionInput));
    double tempX = sector1;
    double tempY = sector2;
    postionMod2 = navArray[courseDirectionInput][2]+((navArray[courseDirectionInput+1][2] - navArray[courseDirectionInput][2])*(courseDirectionInput-(int)courseDirectionInput));
    tempQuad1 = quadrant1;
    tempQuad2 = quadrant2;
    int i;
    for (i = 1; i >= energyToWarp; i++)
    {
        sector1 = sector1 + postionMod1;
        sector2 = sector2 + postionMod2;
        if ((sector1 < 1) || (sector1 >= 9 ) || (sector2 < 1) || (sector2 >= 9))
        {
            //line 3500
        }
        objectLocation = (int) sector 1*24+(int) sector2*3-26;
        if (/*MID$(quadrantMap,objectLocation,2)=" "*/)
        {
            //line 3360
        }
        sector1 = (int) (sector1 - positionMod1);
        sector2 = (int) (sector2 - positonMod2);
        printf(" WARP ENGINES SHUT DOWN AT \n");
        printf("SECTOR %d, %d DUE TO BAD NAVIGATION\n", sector1, sector2);
        //line 3370
    }
    section1 = (int) section1;
    section2 = (int) section2;
    tempObject = '<E>';
    tempObjectPos1 = (int) sector1;
    tempObjectPos2 = (int) sector2;
    //GOSUB 8670
    //GOSUB 3910
    travelTime = 1;
    if(warpInput <1)
    {
        travelTime = 0.1*((int) 10* warpInput;
    }
                 startStardate = startStardate + travelTime;
    double calc = currentStarDate + daysRemaining;
    if (startStardate > calc)
    {
        //line 6220
    }


//------- BLOCK 11  function------
//SEE IF DOCKED THEN GET COMMAND
//GOSUB 6430 function


//------- BLOCK 12 ------
//EXCEEDED QUADRANT LIMITS
    int quadX = 8 * quadrant1 + quadX + energyToWard * postionMod1;
    int quadY = 8 * quadrant2 + quadX + energyToWard * positionMod2;
    quadrant1 = (int) quadX/8;
    quadrant2 = (int) y/8;
    sector1 = (int) quadX-quadrant1*8;
    sector2 = (int) quadY - quadrant2 *8;
    if (sector1 = 0)
    {
        quadrant1 = quadrant1 - 1;
        sector1 = 8;
    }
    if (sector2 = 0)
    {
        quadrant2 = quadrant2 -1;
        sector2 = 8;
    }
    outOfBoundsTf = 0;
    if (quadrant1 < 1)
    {
        outOfBoundsTf = 1;
        quadrant1 = 1;
        sector1 = 1;
    }
    if (quadrant1 > 8)
    {
        outOfBoundsTf =1;
        quadrant1 = 8;
        sector1 = 8;
    }
    if (quadrant2 < 1)
    {
        outOfBoundsTf = 1;
        quadrant2 = 1;
        sector2 = 1;
    }
    if (quadrant2 > 8)
    {
        outOfBoundsTf = 1;
        quadrant2 = 8;
        sector2 = 8;
    }
    if (outOfBoundsTf = 0)
    {
        //function for line 3860
    }
    printf("LT. UHURA REPORTS MESSAGE FROM STARFLEET COMMAND : \n");
    printf("  'PERMISSION TO ATTEMPT CROSSING OF GALACTIC PERIMETER\n");
    printf(" IS HEREBY *DENIED*.  SHUT DOWN YOUR ENGINES.' \n");
    printf("CHIEF ENGINEER SCOTT REPORTS  'WARP ENGINES SHUT DOWN\n");
    printf(" AT SECTOR %d , %d OF QUADRANT %d, %d.\n", sector1, sector2, quadrant1, quadrant2);

    if (startStardate > currentStardate+ daysRemaining)
    {
        //line 6220 function
    }

    int calc1 = 8*quadrant1+quadrent2;
    int calc2 = 8*tempQuad1+tempQuad2;
    if (calc1 = calc2)
    {
        //function for line 3370
    }
    startStardate = startStartdate +1;
    //GOSUB 3910
    //GOTO 1320



//------- BLOCK 13 ------
//MANEUVER ENERGY S/R
    currentEnergy = CurrentEnergy - energyToWarp
                    if (currentEnergy >= 0)
    {
        //RETURN
    }

    printf("SHIELD CONTROL SUPPLIES ENERGY TO COMPLETE MANEUVER.\n");
    currentSheild = currentShield + currentEnergy;
    currentEnergy = 0;
    if (currentShield <= 0)
    {
        currentShield = 0;
    }
    //RETURN


//------- BLOCK 14------
// LONG RANGE SENSOR SCAN CODE

    if (shipDamageArray(3) < 0)
    {
        printf("LONG RANSE SENSORS ARE INOPERABLE.\n")
        //GOTO 1990
    }
    printf("LONG RANGE SCAN FOR QUADRANT %d, %d. \n", quadrant1, quadrant2);
    spacingText = '     -------------------'
                  printf("%c \n", spacingText);
    int i,j, l;
    for (i = quadrant1-1; i <= quadrant1+1; i++)
    {
        scannerArray[1] = -1;
        scannerArray[2] = -2;
        scannerArray[3] = -3;
        for (j = quadrant2 - 1; j <= quadrant2+1; j++)
        {
            if ((i > 0) && (i < 9) && (j > 0) && (j<9))
            {
                scannerArray[j - quadrant2+2] = galaxyInfo[i][j];
                tempInfo[i][j] = galaxyInfo[i][j];
            }
        }
        for (l = 1; l <= 3; l++)
        {
            printf(": \n");
            if (scannerArray[l] < 0)
            {
                print("*** ");
                //GOTO 4230
            }
            //PRINT RIGHT$(STR$(N(L)+1000),3);"
        }
        printf(" : \n");
        printf("%c \n", spacingText);
    }
    //GOTO 1990


    //------- BLOCK 15------
    //PHASOR CONTROL CODE BEGINS HERE
    if (shipDamageArray[4] < 0)
    {
        printf("PHASERS  INOPERATIVE.\n");
        //GOTO 1990
    }
    if (localKlingons > 0)
    {
        //4330
    }

    printf("SCIENCE OFFICER SPOCK REPORTS 'SENSORS SHOW NO ENEMY SHIPS \n");
    printf("/t/t/t/t/t/t/t IN THIS QUADRANT'\n");
    //GOTO 1990

    if (shipDamageArray[8] < 0)
    {
        printf("COMPUTER FAILURE HAMEPERS ACCURACY \n");
    }
    printf("PHASERS LOCKED ON TARGET;\n");
    printf("ENERGY AVAILABLE = %d UNITS. \n", currentEnergy);
    int inputX;
    printf("NUMBER OF UNITS TO FIRE?");
    scanf("%d", &inputX);
    printf("\n");
    if (inputX <= 0)
    {
        //1990
    }
    if (currentEnergy - inputX < 0)
    {
        printf("ENERGY AVAILABLE = %d UNITS. \n", currentEnergy);
    }
    currentEnergy = currentEnergy - inputX;
    if(shipDamageArray[7] < 0)
    {
        inputX = X*rand(1);
    }
    multiTargetMod = (int) (inputX/localKlingons);
    for (i = 1; i <= 3; i++)
    {
        if (klingonData[i][3] <= 0)
        {
            //4670
        }
        multiTargetMod = //(int) ((muliTargetMod/FND(0))*(RND(1)*2));

            if (multiTargetMod > (0.15*klingonData[i][3]))
        {
            //4530
        }
        printf("SENSORS SHOW NO DAMAGE TO ENEMY AT %d, %d.\n", klingonData[i][3], klingonData[i][2]);
        //GOTO 4670
        klingonData[i][3] = klingonData[i][3] - multiTargetMod;
        printf("%d UNIT HIT ON KLINGON AT SECTOR %d,\n", multiTargetMod, klingonData[i][1]);
        printf("%d\n", klingonData[i][2]);
        if (klingonData[i][3] <= 0)
        {
            printf("*** KLINGON DESTROYED ***\n" );
            //GOTO 4580
        }

        printf("   (SENSORS SHOW %d UNITS REMAINING)\n", klingonData[i][3] );
        //GOTO 4670

        localKlingon = localKlingon - 1;
        totalKlingon = totalKlingon - 1;
        tempObjectPos1 = klingonData[i][3];
        tempObjectPos2 = klingonData[i][2];
        tempObject = '   ';
        //GOSUB 8670
        klingonDatai[i][3] = 0;
        galaxyInfo[quadrant1][quadrant2] =  galaxyInfo[quadrant1][quadrant2] - 100;
        tempInfo[quadrant1][quadrant2] =  galaxyInfo[quadrant1][quadrant2];
        if (totalKlingon <= 0)
        {
            //6370
        }
        //GOSUB 6000
        //GOTO 1990
    }


//------- BLOCK 16 -----
//PHOTON TORPEDO CODE BEGINS HERE
    if (currentTorpedos <= 0)
    {
        printf("ALL PHOTON TORPEDOES EXPENDED \n");
        //GOTO 1990
    }
    if (shipDamageArray[5] < 0)
    {
        printf("ALL PHOTON TUBES ARE NOT OPERATIONAL\n");
        //GOTO 1990
    }

    printf("PHOTON TORPEDO COURSE (1-9): \n");
    scanf("%d", courseDirectionInput);
    if (courseDirectionInput = 9)
    {
        courseDirectionInput =  1;
    }
    if ((courseDirectionInput >=1) && (courseDirectionInput < 9)
{
    //4850
    postionMod1 = navArray[courseDirectionInput][1]+(navArray[courseDirectionInput+1][1]-navArray[courseDirectionInput][1])*(courseDirectionInput - (int)courseDirectionInput);
        currentEnergy = currentEnergy - 2;
        currentTorpedos = currentTorpedos -1;
    }

    printf("ENSIGN CHEKOV REPORTS, 'INCORRECT COURSE DATA, SIR' \n");
    //Enter GOTO 1990
    postionMod1 = navArray[courseDirectionInput][1]+(navArray[courseDirectionInput+1][1]-navArray[courseDirectionInput][1])*(courseDirectionInput - (int)courseDirectionInput);
                  currentEnergy = currentEnergy - 2;
                  currentTorpedos = currentTorpedos -1;

                  positionMod2 = navArray[courseDirectionInput][2]+(navArray[courseDirectionInput+1][2]-navArray[courseDirectionInput][2])*(courseDirectionInput - (int)courseDirectionInput);
                  double xTemp = sector1;
                  double yTemp = sector2;

                  printf("TORPEDO TRACK: \n");
                  xTemp = xTemp + postionMod1;
                  yTemp = yTemp + postionMod2;
                  torpedoTracker1 = (int) xTemp+ 0.5;
                  torpedoTracker2 = (int) yTemp + 0.5;

                  if ((torpedoTracker1 < 1) || (torpedoTracker1 > 8) || (torpedoTracker2 < 1) || (torpedoTracker2 > 8))
{
    //5490
}

printf("%d, %d \n", torpedoTracker1, torpedoTracker2);
tempObject = ' ';
             tempObjectPos1 = xTemp;
             tempObjectPos2 = yTemp;
             //GOSUB 8830

             if (mapComparisonTf != 0)  //line 4920 entered below
{
    xTemp = xTemp + postionMod1;
    yTemp = yTemp + postionMod2;
    torpedoTracker1 = (int) xTemp+ 0.5;
        torpedoTracker2 = (int) yTemp + 0.5;
    }

    tempObject = '+K+';
                 tempObjectPos1 = xTemp;
                 tempObjectPos2 = yTemp;
                 //GOSUB 8830
                 if (mapComparisonTf = 0)
{
    //5210
}
printf("*** KLINGON DESTROYED ***\n");
localKlingons = localKlingons - 1;
                totalKlingons = totalKlingon - 1;
                if (totalKlingon <= 0)
{
    //6370
}

for (i = 1; i <= 3; i++)
{
    if ((torpedoTracker1 = klingonData[i][1]) && (torpedoTracker2 = klingonData[i][2]))
        { //5190 entered below
            klingonData[i][3] = 0
            //GOTO 5430
        }
    }

    i = 3;
        klingonData[i][3] = 0;
        //GOTO 5430

        tempObject = ' * ';
        tempObjectPos1 = xTemp;
        tempObjectPos2 = yTemp;
        //GOSUB 8830
        if (mapComparisonTf = 0)
    {
    tempObject = '>B<';
    tempObjectPos1 = xTemp;
    tempObjectPos2 = yTemp;
    //GOSUB 8830
    if (mapComparisonTf = 0)
        {
            //4760 entered below
            printf("PHOTON TORPEDO COURSE(1-9) ");
            scanf("%d", &courseDirectionInput);
            printf("\n");
            if (courseDirectionInput = 9)
            {
                courseDirectionInput = 1;
            }
        }

    }

    printf(" STAR AT %d, %d ABSORBED TORPEDO ENERGY\n", torpedoTracker1, torpedoTracker2);
    //GOSUB 6000
    //GOTO 1990

    tempObject = '>B<';
    tempObjectPos1 = xTemp;
    tempObjectPos2 = yTemp;
    //GOSUB 8830
    if (mapComparisonTf = 0)
        {
            //4760 entered below
            printf("PHOTON TORPEDO COURSE(1-9) \n");
            scanf("%d", &courseDirectionInput);
            if (courseDirectionInput = 9)
            {
                courseDirectionInput = 1;
            }
        }

    printf("*** STARBASE DESTROYED***\n");
    localStarBases = localStarBases - 1;
    starBaseTotal = starBaseTotal - 1;
    if ((starBaseTotal > 0) || (totalKlingons > startStardate - currentStardate-daysRemaining)){
        printf("STARFLEET COMMAND REVIEWING YOUR RECORD TO CONSIDER \n");
        printf("COURT MATERIAL! \n)
    }
     printf("THAT DOES IT, CAPTIAON!! YOU ARE HEREBY RELIVED OF COMMAND \n");
     printf(" AND SENTENCED TO 99 STARDATES AT HARD LABOR ON CYGNUS 12\n");
     //GOTO 6270

     printf("STARFLEET COMMAND REVIEWING YOUR RECORD TO CONSIDER \n");
     printf("COURT MATERIAL! \n")
     starBaseShieldTf = 0;

     tempObjectPos1 = xTemp;
     tempObjectPos2 = yTemp;
     tempObject = '   ';
     //GOSUB 8670

     galaxyInfo[quadrant1][quadrant2] = localKlingons*100+localStarBases*10+localStars;
     tempInfo[quadrant1][quadrant2] = galaxyInfo[quadrant1][quadrant2];
     //GOSUB 6000
     //GOTO 1990

     printf("TORPEDO MISSED \n");
     //GOSUB 6000
     //GOTO 1990


//------- BLOCK 17 -----
//SHIELD CONTROL
    if (shipDamageArray[7] < 0){
        printf("SHIELD CONTROL INOPERABLE \n");
        //GOTO 1990
    }
    printf("ENERGY AVAILABLE = %d\n", currentEnergy + currentShield);
    int energyInput;
    printf("NUMBER OF UNITS TO SHEILDS?");
    scanf("%d", &energyInput);
    printf("\n");

    if ((energyInput < 0) || (currentShield = energyInput)){
        printf("<SHEILDS UNCHANGED>\n");
        //GOTO 1990
    }

    if (energyInput <= currentEnergy + currentShield)
        { //line 5630 entered below
            currentEnergy = currentEnergy + currentShield - energyInput;
            currentShield = energyInput;
            printf("DEFLECTOR CONTROL ROOM REPORT: \n");
            printf(" 'SHIELDS NOW AT UNITS PER YOUR COMMAND.' \n");
            //GOTO 1990
        }


//------- BLOCK 18-----
//DAMAGE CONTROL
    if (shipDamageArray[6] >= 0){
        //5910
    }
    printf("DAMAGE CONTROL REPORT NOT AVAILABLE \n");
    if (starBaseShieldTf = 0){
        //1990
    }

    repairTime = 0;
    for (i = 1; i <= 8; i++){
        if(shipDamageArray[i] = 1){
            repairTime = repairTime + 0.1;
        }
    }

    if (repairTime = 0){
        //1990
    }
    printf("\n"); //print :
    repairTime = repairTime + quadrantDamageMod;
    if (repairTime >= 1){
        repairTime = 0.9;
    }

    printf("TECHNICIANS STANDING BY TO EFFECT REPAIRS TO YOUR SHIP;\n");
    printf("ESTIMATED TIME TO REPAIR: %d STARDATES \n", 100*(int) 100*repairTime);
    printf("WILL YOU AUTHORIZE THE REPAIR ORDER (Y/N)?")
    scanf("%c", &tempObject);
    printf("\n");

    if (tempObject != 'y'){
        //1990
    }
    for (i = 1; i <= 8; i++){
        if (navArray[i] < 0){
            navArray[i] = 0;
        }
    }
    startStardate = startStardate + repairTime+ 0.1;
    printf("\n");
    printf("DEVICE \t STATE OF REPAIR\n");
    int repairState; //R1
    for (repairState = 1; repairState <= 8){
        //GOSUB 8790
        //PRINTG2$;
        //LEFT$(Z$,25-LEN(G2$));
        //INT(D(R1)*100)*.01
    }
    printf("/n");
    if (starBaseShieldTf != 0){ //5720 entered below
         repairTime = 0;
        for (i = 1; i <= 8; i++){
            if(shipDamageArray[i] = 1){
                repairTime = repairTime + 0.1;
            }
        }
    }
    //GOTO 1990



//------- BLOCK 19-----
//KLINGONS SHOOTING
    if (localKlingons <= 0){
        //RETURN
    }
    if (starBaseShieldTf != 0){
        printf("STARBASE SHEILDS PROTECT THE ENTERPRISE \n");
        //RETURN
    }

    for (i = 1; i <= 3; i++){
        if (klingonData[i][3] <= 0){
            //6200
        }
        enemyHit = (int) ((klingonData[i][3]/FND(1))*(2+rand(1)));
        currentShield = currentShield - enemyHit;
        klingonData[i][3] = klingonData[i][3]/(3*rand(0));

        printf("%d UNIT HIT ON ENTERPRISE FROM SECTOR %d, %d \n", klingonData[i][1], klingonData[i][2]);
        if (currentShield <= 0){
            //6240
        }
        printf("\t\t\t <SHIELDS DOWN TO %d UNITS \n", currentShield);
        if (enemyHit < 20){
            //6200
        }
        if ((rand(1)>0.6) || (enemyHit/currentShield <= 0.02)){
            //6200
        }
        rComponent = FNR(1);
        shipDamageArray[rComponent] =  shipDamageArray[rComponent]-enemyHit/currentShield-0.5*rand(1);
        //GOSUB 9780
        printf("DAMAGE CONTROL REPORTS %c DAMAGED BY THE HIT \n", shipPartName);
    }
        //RETURN



//------- BLOCK 20-----
//END OF GAME
    printf("IT IS STARDATE %d\n", startStardate);
    //GOTO 6270
    printf("\n");
    printf("THE ENTERPRISE HAS BEEN DESTORYED. THE FEDERATION\n");
    printf("WILL BE CONQUERED \n");
    //GOTO 6220
    printf("THERE WERE %d KLINGON BATTLE CRUISERS LEFT AT\n", totalKlingon);
    printf("THE END OF YOUR MISSION");
    printf("\n"); //print :
    print("\n"); //print :
    if (starBaseTotal = 0){
        //6360
    }

    printf("THE FEDERATION IS IN NEED OF A NEW STARSHIP COMMANDER \n");
    printf("FOR A SIMILAR MISSION -- IF THERE IS A VOLUNTEER \n");
    printf("\n LET HIM STEP FORWARD AND ENTER 'AYE' \n");
    scanf("%c", &tempObject);
    if ((tempObject == 'AYE') || (tempObject == 'Aye') || (tempObject == 'aye')){
        //10
    }
    return(0);

    printf("CONGRATULATIONS, CAPTAIN! THE LAST KLINGON BATTLE CRUISER\n");
    printf("MENACING THE FEDERATION HAS BEEN DESTROYED. \n");
    printf("\n");
    int efficencyRate = 1000*(startKlingon/(pow(startStardate - currentStardate, 2)))
    printf("YOUR EFFICIENCY RATING IS %d\n", effiecencyRate);



//------- BLOCK 21-----
//SHORT RANGE SENSOR SCAN & STARTUP SUBROUTINE
    for (i = sector1 - 1; i <= sector1 + 1; i++){
        for (j = sector2 - 1; j <= sector2 + 1; j++){
            if (((int)(i + 0.5) < 1) || ((int)(i + 0.5) > 8) || ((int) (j + 0.5) < 1) || ((int) (j + 0.5) > 8)){
                //6540
            }
            tempObject = ">B<";
            tempObjectPos1 = i;
            tempObjectPos2 = j;
            //GOSUB 8830
            if (mapComparisonTf = 1){
                //6580
            }
        }
    }
    starBaseShieldTf = 0;
    //GOTO 6650

    starBaseShieldTf = 1;
    shipCondition = 'DOCKED';
    currentEnergy = maxEnergy;
    currentTorpedos = maxTorpedos;
    printf("SHIELDS DROPPED FOR DOCKING PURPOSES \n");

    currentShield = 0;
    //GOTO 6720
    if (localKlingons > 0){
        shipCondition = '*RED*';
        //GOTO 6720
    }
    shipCondition  = 'GREEN';
    if (currentEnergy < maxEnergy*0.1){
        shipCondition = 'YELLOW';
    }

    if (shipDamageArray[2]){
        //6770
    }
    printf("\n");
    printf("*** SHORT RANGE SENSORS ARE OUT ***\n");
    printf("\n");
    //RETURN

    spacingText = "---------------------------------" ;
    printf("%c\n", spacingText);
    for (i =1; i <= 8; i++){
        for (j = (i-1*24+1); j <=  (i-1*24+22); j++){
            //PRINT " ";MID$(Q$,J,3);
        }
        //ON i GOTO 6850,6900,6960,7020,7070,7120,7180,7240
        printf("             STARDATE             %d\n", (int) (startStardate*10)*0.1);
        //GOTO 7260
        printf("            CONDITION               %d\n", shipCondition);
        //GOTO 7260
        printf("            QUADRANT               %d, %d\n", quadrant1, quadrant2);
         //GOTO 7260
        printf("            SECTOR               %d, %d\n", sector1, sector2);
         //GOTO 7260
          printf("            PHOTON TORPEDOES               %d\n", (int) currentTorpedos);
         //GOTO 7260
          printf("            TOTAL ENERGY               %d\n", (int) currentEnergy+currentShield);
         //GOTO 7260
          printf("            SHIELDS               %d\n", (int) currentShield);
         //GOTO 7260
          printf("            KLINGONS REMAINING               %d\n", (int) totalKlingons);
    }
    printf("%c\n", spacingText);
    //RETURN



//------- BLOCK 22-----
// LIBRARY COMPUTER CODE
    if (shipDamageArray[8]<0){
        printf("COMPUTER DISABLED\n");
        //GOTO 1990
    }

    printf("COMPUTER ACTIVE AND AWAITING COMMAND: \n");
    scanf("%d", &libInput);
    printf("\n");
    if (libInput < 0){
        //1990
    }
    printf("\n");
    //ON A+1 GOTO 7540,7900,8070,8500,8150,7400

    printf("FUNCTIONS AVAILABLE FROM LIBRARY-COMPUTER : \n");
    printf("   0 = CUMULATIVE GALACTIC RECORD\n");
    printf("   1 = STATUS REPORT\n");
    printf("   2 = PHOTON TORPEDO DATA\n");
    printf("   3 = STARBASE NAV DATA\n");
    printf("   4 = DIRECTION/DISTANCE CALCULATOR\n");
    printf("   5 = GALAXY 'REGION NAME' MAP\n");
    printf("\n");
    //GOTO 7320



//------- BLOCK 23-----
// SETUP TO CHANGE CUM GAL RECORD TO GALAXY MAP
    libMenu = 0;
    noNumberNamesTf = 1;
    printf("                        THE GALAXY\n");
    //GOTO 7550


//------- BLOCK 24-----
//CUM GALACTIC RECORD
//INPUT "DO YOU WANT A HARDCOPY? IS THE TTY ON (Y/N) ";A$
//IF A$="Y" THEN POKE 1229,2 : POKE1237,3 : NULL1
    printf("\n");
    printf("\t");
    printf("\n COMPUTER RECORD OF GALAXY FOR QUADRANT  %d, %d\n" quadrant1, quadrant2);
    printf("\n");
    printf("       1     2     3     4     5     6     7     8\n");
    spacingText ='     ----- ----- ----- ----- ----- ----- ----- -----'
    printf("%c\n", spacingText);

    for (i = 1; i <= 8; i++){
        print("%d  ", i)
        if(libMenu = 0){
            //7740
        }
        for (j = 1; j <= 8; j++){
            printf("   ");
            if (tempInfo[i][j]=0){
                printf("***");
                //GOTO 7720
            }
            //PRINT RIGHT$(STR$(Z(I,J)+1000),3);
        }

        //GOTO 7850
        quadrantName1 = i;
        quadrantName2 = 1;
        //GOSUB 9030
        printAdvance = (int) (15-0.5*strlen(shipPartName));
        printf("%d %c\n", printAdvance, shipPartName); //TAB()?

        quadrantName2 = 5;
        //GOSUB 9030
        printAdvance = (int) (39-0.5*srtlen(shipPartName));
        printf("%d %c\n", printAdvance, shipPartName); //tab()?

        printf("\n");
        printf("%c\n", spacingText);
    }



//------- BLOCK 25-----
//STATUS REPORT
    printf("   STATUS REPORT : \n");
    sPluralize = '';
    if (totalKlingons > 1){
        sPluralize = 'S';
    }

    printf("KLINGON %c LEFT : %d\n", sPluralize, totalKlingons);

    printf("MISSION MUST BE COMPLETED IN %d STARDATES \n", (int)((currentStardate+daysRemaining-startStardate)*10));


    sPluralize = 'S';
    if (starBaseTotal < 2){
        sPluralize = ' ';
        if (starBaseTotal < 1){
            //8010
        }
    }

    printf(" THE FEDERATION IS MAINTAINING %d STARBASE %c IN THE GALAXY \n", starBaseTotal, sPluralize);
    //GOTO 5690

    printf("YOUR STUPIDITY HAS LEFT YOU ON YOUR OWN IN\n");
    printf("THE GALAXY -- YOU HAVE NO STARBASES LEFT!\n");
    //GOTO 5690



//------- BLOCK 26-----
//TORPEDO, BASE, NAV, D/D CALCULATOR
    if (localKlingons <= 0){
        //4270
    }

    sPluralize = ' ';
    if (localKlingons > 1){
        sPluralize = 'S';
    }

    printf("FROM ENTERPRISE TO KLINGON BATTLE CRUISER %c\n", sPluralize);
    libMenu = 0;

    for (int i = 1; i <= 3; i++){
        if (klingonData[i][3] <= 0){
            //8480
        }
        warpInput = klingonData[i][1];
        inputX = klingonData[i][2];
        tempTorpedoInitialCoord1 = sector1;
        tempTorpedoInitialCoord2 = sector2;
        //GOTO 8220

        printf("DIRECTION/DISTANCE CALCULATOR : \n");
        printf("YOU ARE AT QUADRANT %d, %d SECTOR %d, %d\n", quadrant1, quadrant2, sector1, sector2);
        printf("PLEASE ENTER\n");
        printf("INITIAL COORDINATES (X,Y) ");
        scanf("%d %d", &tempTorpedoInitialCoord1, &tempTorpedoInitialCoord2);
        printf("\nFINAL COORDINATES (X,Y) ")
        scanf("%d %d", &tempTorpedoFinalCoord1, &tempTorpedoFinalCoord2);
        printf("\n");

        tempTorpedoFinalCoord2 = tempTorpedoFinalCoord2 - tempTorpedoInitialCoord2;
        tempTorpedoInitialCoord2 = tempTorpedoInitialCoord1 - tempTorpedoFinalCoord1;

        if (tempTorpedoFinalCoord2 < 0){
            //8350
        }

        if (tempTorpedoInitialCoord2 < 0){
            //8410
        }

        if (tempTorpedoFinalCoord2 > 0){
                //8280
        }

        if (tempTorpedoInitialCoord2 = 0){
            tempTorpedoInitialCoord1 = 5;
            //GOTO 8290
        }

        tempTorpedoInitialCoord1 = 1;

        if (abs(tempTorpedoInitialCoord2) <= abs(tempTorpedoFinalCoord2)){
            //8330
        }

        printf("DIRECTION = %d\n ", tempTorpedoInitialCoord1+(((abs(tempTorpedoInitialCoord2)-abs(tempTorpedoFinalCoord2))+abs(tempTorpedoInitialCoord2))/abs(tempTorpedoFinalCoord2));
        //GOTO 8460
        printf("DIRECTION = %d\n", tempTorpedoInitialCoord1+(abs(tempTorpedoInitialCoord2)/abs(tempTorpedoFinalCoord2)));
        //GOTO 8460

        if (tempTorpedoInitialCoord2 > 0){
            tempTorpedoInitialCoord1 = 3;
            //GOTO 8420
        }

        if (tempTorpedoFinalCoord2 != 0){
            tempTorpedoInitialCoord1 = 5;
            //GOTO 8290
        }

        tempTorpedoInitialCoord1 = 7;
        if (abs(tempTorpedoInitialCoord2) >= abs(tempTorpedoFinalCoord2)){
            //8450
        }

        printf("DIRECTION = %d\n", tempTorpedoInitialCoord1++(((abs(tempTorpedoFinalCoord2)-abs(tempTorpedoInitialCoord2))+abs(tempTorpedoFinalCoord2))/abs(tempTorpedoFinalCoord2)));
        //GOTO 8460

        printf("DIRECTION = %d\n", tempTorpedoInitialCoord1+(abs(tempTorpedoFinalCoord2)/abs(tempTorpedoInitialCoord2)));

        printf("DISTANCE = %f\n", sqrt(pow(tempTorpedoFinalCoord2, 2) + pow(tempTorpedoInitialCoord2, 2)));
        if (libMenu = 1){
            //1990
        }
    }

    //GOTO 1990

    if (localStarBases != 0){
        printf("FROM ENTERPRISE TO STARBASE : \n");
        tempTorpedoInitialCoord1 = starBaseSector1;
        tempTorpedoFinalCoord2 = starBaseSector2;
        //GOTO 8120
    }

    printf("MR. SPOCK REPORTS, ' SENSORS SHOW NO STARBASES IN THIS\n");
    printf(" QUADRANT.\n");
    //GOTO 1990



//------- BLOCK 27-----
// FIND EMPTY PLACE IN QUADRANT (FOR THINGS)
    int R1 = FNR(1);
    int R2 = FNR(1);
    tempObject = '   ';
    tempObjectPos1 = R1;
    tempObjectPos2 = R2;
    //GOSUB 8830
    if (mapComparisonTf = 0){
            //8590
    }

    //RETURN



//------- BLOCK 28-----
//INSERT IN STRING ARRAY FOR QUADRANT
    objectLocation = (int) (tempObjectPos2-0.5)*3 + (int) (tempObjectPos1-0.5)*24+1;

    if(strlen(tempObject) != 3){
        printf("ERROR\n");
        //RETURN
    }

    if (objectLocation = 1){
        shipCondition = tempObject+ //RIGHT$(quadrantMap, 189);
        //RETURN
    }

    if (objectLocation = 190){
        shipCondition = //LEFT$(quadrantMap)+tempObject;
        //RETURN
    }

    shipCondition = //LEFT$(quadrantMap, objectLocation-1)+tempObject + RIGHT$(quadrantMap, 190 - objectLocation);
    //RETURN



//------- BLOCK 29-----
//PRINTS DEVICE NAME

//ON R1 GOTO 8792,8794,8796,8798,8800,8802,8804,8806

    shipPartName = 'WARP ENGINES';
    //RETURN

    shipPartName = 'SHORT RANGE SENSORS';
    //RETURN

    shipPartName = 'LONG RANGE SENSORS';
    //RETURN

    shipPartName = 'PHASER CONTROL';
    //RETURN

    shipPartName = 'PHOTON TUBES';
    //RETURN

    shipPartName = 'DAMAGE CONTROL';
    //RETURN

    shipPartName = 'SHIELD CONTROL';
    //RETURN

    shipPartName = 'LIBRARY-COMPUTER';
    //RETURN




//------- BLOCK 30-----
// STRING COMPARISON IN QUADRANT ARRAY
    tempObjectPos1 = (int) tempObjectPos1 + 0.5;
    tempObjectPos2 = (int) tempObjectPos2 + 0.5;
    objectLocation = (tempObjectPos2 - 1)*3+(tempObjectPos1 - 1)*24+1;
    mapComparisonTf = 0;

    if (/*MID$(quadrantMap, objectLocation,3)*/ != tempObject){
        //RETURN
    }

    mapComparisonTf = 1;
    //RETURN




//------- BLOCK 31-----
//QUADRANT NAME IN G2$ (shipPartName) FROM Z4, Z5 (=Q1,Q2) (quadrantName1, quadrantName2) (=quadrant1, quadrant2)
//CALL WITH G5 (noNumberNamesTf) = 1 TO GET REGION NAME ONLY
    if (quadrantName2 <= 4){
        //ON Z4 GOTO 9040,9050,9060,9070,9080,9090,9100,9110
    }

    //GOTO 9120

    shipPartName = 'ANTARES';
    //GOTO 9210

    shipPartName = 'RIGEL';
    //GOTO 9210

    shipPartName = 'PROCYON';
    //GOTO 9210

    shipPartName = 'VEGA';
    //GOTO 9210

    shipPartName = 'CANOPUS';
    //GOTO 9210

    shipPartName = 'ALTAIR';
    //GOTO 9210

    shipPartName = 'SAGITTARIUS';
    //GOTO 9210

    shipPartName = 'POLLUX';
    //GOTO 9210

    //ON Z4 GOTO 9130,9140,9150,9160,9170,9180,9190,9200

    shipPartName = 'SIRIUS';
    //GOTO 9210

    shipPartName = 'DENEB';
    //GOTO 9210

    shipPartName = 'CAPELLA';
    //GOTO 9210

    shipPartName = 'BETELGEUSE';
    //GOTO 9210

    shipPartName = 'ALDEBARAN';
    //GOTO 9210

    shipPartName = 'REGULUS';
    //GOTO 9210

    shipPartName = 'ARCTURUS';
    //GOTO 9210

    shipPartName = 'SPICA';

    if (noNumberNamesTf != 0){
        //ON Z5 GOTO 9230,9240,9250,9260,9230,9240,9250,9260
    }

    //RETURN

    shipPartName = shipPartName + ' I';
    //RETURN

    shipPartName = shipPartName + ' II'
    //RETURN

    shipPartName = shipPartName + ' III';
    //RETURN

    shipPartName = shipPartName + ' IV';
    //RETURN
}






//function from line 2700
void line2700()
{
//gosub  6000
    queueDamageReportTf = 0;
    warpSpeedDamageReportTf = warpInput;
    if (warpInput >= 1)
    {
        warpSpeedDamageReportTf = 1;
    }
}

void line2880()
{
    if (rand(1) > 0.2)
    {
        //line 3070
    }
}

//8790
void line8790
