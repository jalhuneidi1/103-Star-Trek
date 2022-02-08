/* ------ MID$ ------*/
//function to return a substring from a specific index up to a given length
//print statement in block would look like printf("%s", parseMID(VARIABLE NAME, START INDEX NUMBER, END INDEX NUMBER))
char parseMID(char param[], int startIndex, int length){
    int i;
    char *result;
    result = malloc(length+1);

    for (i = 0; i < length; i++){
        *(result + i) = *(param + startIndex);
        param++;
    }

    *(result + i) = '\0';
    return result; // return substring starting from index given

}

/* ------ RIGHT$ ------*/
//function to return a substring from the right up to the given length
//print statement in block would look like printf("%s", parseRIGHT(VARIABLE NAME, lengthNumber))
char parseRIGHT(char *param, int length){
    int i;
    int j = strlen(param) - 1;
    char *result;
    result = malloc(length + 1);

    for (i = 0; i < length; i++, j--){
        *(result + i) = *(param+j);
        //i++
    }

    *(result + i) = *(param + j);
    return result; //return substring starting from the right
}

/* ------ LEFT$ ------*/
//function to return a substring from the left up to the given length
//print statement in block would look like printf("%s", parseLEFT(VARIABLE NAME, lengthNumber))
char* parseLEFT(char* param, int length){
    int i = 0;
    char *result;
    result = malloc(length+1); //allocate memory for th character array result

    while (i < length){
        *(result + 1) = *(param + i);
        i++;
    }

    *(result + 1) = '\0';
    return result; // return a substring from the left
}
