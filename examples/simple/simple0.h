// Never include this file (simple0.h) directly. include simple.h instead.

 
 class Simple : public java::lang::Object {
     public:
         Simple(jobject _jthis, bool copy);
         Simple(const Simple &);
         static Simple cast(const java::lang::Object &);
         
  protected:
  Simple();
  public:
  Simple(jint int_0);
  ~Simple();
  jint getValue();
 }; // end class Simple

