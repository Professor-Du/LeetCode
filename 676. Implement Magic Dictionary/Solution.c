


typedef struct {
   int  num;
   char **dict;
} MagicDictionary;


MagicDictionary* magicDictionaryCreate() {
  MagicDictionary *p = malloc (sizeof (MagicDictionary));
  p->num = 0;
  p->dict = NULL;
  return p;
}

void magicDictionaryBuildDict(MagicDictionary* obj, char** dictionary, int dictionarySize) {
  obj->dict = dictionary;
  obj->num = dictionarySize;
}

bool magicDictionarySearch(MagicDictionary* obj, char* searchWord) {  // Faster then 100% solutions!!!
  int i, j, misCnt;
  for (i = 0; i < obj->num; i++) {
    for (j = 0, misCnt = 0; obj->dict[i][j] != '\0' && searchWord[j] != '\0'; j++) {
      if (obj->dict[i][j] == searchWord[j]) {
        continue;
      }
      if (++misCnt > 1) {
        break;
      }
    }
    if (misCnt == 1 && obj->dict[i][j] == searchWord[j]) {
      return true;
    }
  }
  return false;
}

void magicDictionaryFree(MagicDictionary* obj) {
  free (obj);
}

/**
 * Your MagicDictionary struct will be instantiated and called as such:
 * MagicDictionary* obj = magicDictionaryCreate();
 * magicDictionaryBuildDict(obj, dictionary, dictionarySize);

 * bool param_2 = magicDictionarySearch(obj, searchWord);

 * magicDictionaryFree(obj);
*/