int most_common(const char *filename)
{
char frequency[26];
int ch = 0;

FILE *fileHandle;
if((fileHandle = fopen(filename, "r")) == NULL){
    return -1;
}

for (ch = 0; ch < 26; ch++)
    frequency[ch] = 0;

while(1){
    ch = fgetc(fileHandle);
    if (ch == EOF) break;

    if ('a' <= ch && ch  <= 'z')
        frequency[ch - 'a']++;
    else if ('A' <= ch && ch <= 'Z')
        frequency[ch - 'A']++;
}

int max = 0;
for (int i = 1; i < 26; ++i)
  if (frequency[i] > frequency[max])
      max = i;

return max;
}
