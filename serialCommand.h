class SerialCommand{
  long bautRate;
  private:
  public:
  String modul;
  String action;
  String data1;
  String data2;
  String data3;

    void setup(){
      Serial.begin(bautRate);  
    }
    void setBautRate(long b){
      bautRate=b;
    }
    void send(String m,String a,String d1,String d2,String d3){
          String senddata="#"m+"*"+a+"*"+d1+"*"+d2+"*"+d3+"&";
          Serial.print(senddata);
 
    }
    void read(){
      modul="";
      action="";
      data1="";
      data2="";
      data3="";
      String sdata="";
      if(Serial.available()){
          sdata=Serial.readString();
          int asama=0;
          for(int i=0;i<sdata.length();i++){
            if(sdata[i]=='#') asama=1;
            if(sdata[i]!='#'&&sdata[i]!='*'&&sdata[i]!='&'){
              if(asama==1) modul=modul+sdata[i];  
              if(asama==2) action=action+sdata[i];  
              if(asama==3) data1=data1+sdata[i];  
              if(asama==4) data2=data2+sdata[i];  
              if(asama==5) data3=data3+sdata[i];  
            }
            if(sdata[i]=='*') asama++;
          }
      }
    }

};
