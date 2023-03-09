#define DATA_DUMP "/location.dat"

bool writeFile(fs::FS &fs, const char * path, const char * message){
 
  File file = fs.open(path, FILE_WRITE);
  if(!file){
    return false;
  }
  if(file.print(message)){
    return true;
  }
  file.close();
  return false;
}

bool readFile(fs::FS &fs, const char * path){

  File file = fs.open(path);
  if(!file){
    return false;
  }

  while(file.available()){
    Serial.write(file.read());
  }
  file.close();
  return true;
}

bool appendFile(fs::FS &fs, const char * path, const char * message){

  File file = fs.open(path, FILE_APPEND);
  if(!file){
    return false;
  }
  if(file.print(message)){
      file.close();
      return true;
  }
  
  file.close();
  return false;

}
