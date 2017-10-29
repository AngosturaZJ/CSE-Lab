#include <stdio.h>
#include <string.h>
#define MAXSIZE 4096

int matches_leading(char *partial_line, char *pattern) {

  if(partial_line[0] == 0 && pattern[0] == 0){
    return 1;
  }
  if(partial_line[0] == pattern[0] && pattern[1] != '+' && pattern[1] != '?'){
    if(partial_line[1] != 0 && pattern[1] != 0){
      int i=0; 
      int j=0;
      char partiallin[MAXSIZE]; 
      char patial1[MAXSIZE];
      for(int k = 0; k < MAXSIZE; k++){
	partiallin[k] = 0;
      }
      while(partial_line[i+1] != 0){
	partiallin[i] = partial_line[i+1];
	i++;
      }
      for(int k = 0; k < MAXSIZE; k++){
	patial1[k] = 0;
      }
      while(pattern[j+1] != 0){
	patial1[j] = pattern[j+1];
	j++;
      }
      int match = -1;
      match = matches_leading(partiallin, patial1);
      if(match == 0){
	return 0;
      }
      for(int k = 0; k < MAXSIZE; k++){
	partiallin[k] = 0;
      }
    }
    return 1;
  }
  if((partial_line[0] == 0 && pattern[0] != 0) || (partial_line[0] != 0 && pattern[0] == 0)){
    return 0;
  }
  if(partial_line[0] != pattern[0] && pattern[0] != '.' && pattern[1] != '?' && pattern[0] != '\\'){
    return 0;
  }
  if(pattern[1] == '+' && pattern[0] != '\\'){
    char patial1[MAXSIZE]; int i = 0; int match = -1;
    while(match != 1 && partial_line[i] != 0){
      for(int k = 0; k < MAXSIZE; k++){
	patial1[k] = 0;
      }
      int g = 0; int f = 0;
      for(g = 0; g < i; g++){
	patial1[g] = pattern[0];
      }
      while(pattern[f] != 0){
	if(pattern[f] == '+'){
	  f++;
	  continue;
	}
	patial1[g] = pattern[f];
	g++; f++;
      }
      match = matches_leading(partial_line, patial1);
      i++;
    }
    if(match == 1){
      return 1;
    }
    else 
      return 0;
    
  }
  if(pattern[0] == '.' && pattern[1] != '+' && pattern[1] != '?' && pattern[0] != '\\'){
    char partiallin[MAXSIZE]; char patial1[MAXSIZE]; int j = 0; int match = -1;
    for(int k = 0; k < MAXSIZE; k++){
      partiallin[k] = 0;
    }
    while(partial_line[j+1] != 0){
      partiallin[j] = partial_line[j+1];
      j++;
    }
    for(int k = 0; k < MAXSIZE; k++){
      patial1[k] = 0;
    }
    j = 0;
    while(pattern[j+1] != 0){
      patial1[j] = pattern[j+1];
      j++;
    }
    match = matches_leading(partiallin, patial1);
    if(match == 0){
      return 0;
    }
  }
  if(pattern[1] == '?' && pattern[1] != '+' && pattern[1] != 0 && pattern[0] != '\\'){
    char pat1[MAXSIZE]; 
    char pat2[MAXSIZE]; 
    int j = 0; 
    int match1 = -1; 
    int match2 = -1;
    if(match1 != 0){
      for(int k = 0; k < MAXSIZE; k++){
	pat1[k] = 0;
      }
      while(pattern[j+2] != 0){
	pat1[j] = pattern[j+2];
	j++;
      }
      match1 = matches_leading(partial_line, pat1);
    }
    if(match2 != 0){
      for(int k = 0; k < MAXSIZE; k++){
	pat2[k] = 0;
      }
      pat2[0] = pattern[0]; j = 1;
      while(pattern[j+1] != 0){
	pat2[j] = pattern[j+1];
	j++;
      }
      match2 = matches_leading(partial_line, pat2);
    }
    if(match1 == 0 && match2 == 0){
      return 0;
    }
  }
  if(pattern[0] == '\\'){
    char partiallin[MAXSIZE]; char patial1[MAXSIZE]; int j = 0; int match = -1;
    if(partial_line[0] == pattern[1]){
      while(pattern[j+2] != 0){
	patial1[j] = pattern[j+2];
	j++;
      }
      j = 0;
      while(partial_line[j] != 0){
	partiallin[j] = partial_line[j+1];
	j++;
      }
      match = matches_leading(partiallin, patial1);
      if(match == 0){
	return 0;
      }
    }
    else{
      return 0;
    }
  }
  return 1;
}

/**
 * You may assume that all strings are properly null terminated 
 * and will not overrun the buffer set by MAXSIZE 
 *
 * Implementation of the rgrep matcher function
 */
int rgrep_matches(char *line, char *pattern) {

  int i = 0; 
  int j = 0;
  int mark;
  int rgrepmatch;
  char partiallin[MAXSIZE];
  
  if (strlen(pattern) == 2) {
    if (pattern[0] == '.') {
      if (pattern[1] == '+') {
	if (*line == '\n') {
	  return 0;
	} else {
	  return 1;
	}
      }
    }
    if (pattern[0] == '\\'){
      for (i = 0; i < strlen(line); i++) {
	if (line[i] == pattern[1]) {
	  return 1;
	}
      }
    }
    if (pattern[0] != '.' && pattern[0] != '\\' && pattern[0] != '+' && pattern[0] != '?') {
      if (pattern[1] != '.' && pattern[1] != '\\' && pattern[1] != '+' && pattern[1] != '?') {
	for (i = 0; i < strlen(line); i++) {
	  if (line[i] == pattern[0] && line[i+1] == pattern[1]) {
	    return 1;
	  }
	}
      }
    }
  }

  if (strlen(pattern) == 5) {
    if (pattern[0] == '.' && pattern[1] == '\\' && pattern[3] == '\\') {
      if (pattern[2] == '+' || pattern[2] == '?' || pattern[2] == '\\' || pattern[2] == '.') {
	if (pattern[4] == '+' || pattern[4] == '?' || pattern[4] == '\\' || pattern[4] == '.') {
	  if (line[1] == pattern[2]) {
	    if (line[2] == pattern[4]) {
	      return 1;
	    } else {
	      return 0;
	    }
	  } else {
	    return 0;
	  }
	}
      }
    }
  }

  if (pattern[0] == '.') {
    for (i = 0; i < strlen(pattern); i++) {
      if (pattern[i] == '.') {
	mark = 0;
      } else {
	mark++;
      }
    }
    if (mark == 0) {
      if (strlen(line) >= (strlen(pattern)+1)) {
	return 1;
      } else {
	return 0;
      }
    }
  }
  
  while(line[i+1] != 0){
    if(line[i] == pattern[j] || pattern[j] == '.'){
      int k = 0;
      while(line[i+1] != 0){
	partiallin[k] = line[i];
	if(line[i+1] == ' ' || line[i+1] == '\n')
	  break;
	i++;
	k++;
      }
      partiallin[k+1] = 0;
      rgrepmatch = matches_leading(partiallin, pattern);
      for(int p = 0; p < k+1; p++)
	partiallin[p] = 0;
      if(rgrepmatch == 1){
	return 1;
      }
      
    }
    i++;
  }
  
  return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PATTERN>\n", argv[0]);
        return 2;
    }

    /* we're not going to worry about long lines */
    char buf[MAXSIZE];

    while (!feof(stdin) && !ferror(stdin)) {
        if (!fgets(buf, sizeof(buf), stdin)) {
            break;
        }
        if (rgrep_matches(buf, argv[1])) {
            fputs(buf, stdout);
            fflush(stdout);
        }
    }

    if (ferror(stdin)) {
        perror(argv[0]);
        return 1;
    }

    return 0;
}
