#define DATA_AMOUNT 4
#define HEADER '$'
#define DIVIDER ' '
#define ENDING ';'

bool receiverFlag = false;
byte receivedData[DATA_AMOUNT];
byte dataIndex = 0;


void bluetooth_receiver_handler(){
  while(Serial.available() > 0){
    char incomingByte = Serial.read();

    //Se recibe un nuevo mensaje
    if(incomingByte == HEADER){
      dataIndex = 0;      
      for(int i=0; i<DATA_AMOUNT; i++){
        receivedData[i] = 0;
      }
    }
    
    else if(incomingByte == ENDING)
      receiverFlag = true;
      
    else if(incomingByte != DIVIDER){
       receivedData[dataIndex] = incomingByte - '0';
       dataIndex++;
    }   
  }
}
