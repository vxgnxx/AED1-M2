bool checkNext_r(char *s, int *subSize, int i, char **subS){
    char *temp = &s[i];
    if(s[i] == '\0' || s[i+1] == '\0'){
        subS[*subSize] = temp;
        return 1;
    }

    if(s[i] == s[i+1] || (s[i]+32) == s[i+1]){
        *subSize += 1;
        checkNext_r(s, subSize, i+1, subS);
        *subS = (char *) realloc((*subS), (*subSize) * sizeof(char));
        subS[(*subSize) - 1] = temp;
        return 1;
    } else if (s[i] == (s[i+1]+32) || s[i] + s[i+1]){
        *subSize += 1;
        checkNext_r(s, subSize, i+1, subS);
        *subS = (char *) realloc(*subS), (*subSize) * sizeof(char));
        subS[(*subSize) - 1] = temp;
        return 1;
    } else {
        return 0;
    }
}

char* longestNiceSubstring(char* s) {
    int subSize = 0;
    int *subSizeP = &subSize;
    int sizeS = 0;
    int resSize = 0;
    char *subString = (char *)malloc(sizeof(char));
    char *result = (char *)malloc(sizeof(char));

    while(s[sizeS] != '\0'){
        sizeS++;   }

    for(int i = 0; i < sizeS; i++){
        checkNext_r(s, subSizeP, i, &subString);
        resSize = 0;
        while(s[resSize] != '\0'){
            resSize++;
                }
        if(subSizeP > resSize){
            result = (char *)realloc(subString, (*subSizeP) * sizeof(char));
            strcpy(result, subString);
        }
        *subSizeP = 0;    }
    
    return result;
}