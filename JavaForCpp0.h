// Never include this file (JavaForCpp0.h) directly. include JavaForCpp.h instead.


// start_segment_index = 0
// start_segment_index = 1
// segment_index = 0
// classesSegList=[interface java.lang.Runnable]


// class_index = 0 clss=interface java.lang.Runnable

 namespace java{
  namespace lang{
   
   class Runnable : public Object {
       public:
           Runnable(jobject _jthis, bool copy);
           Runnable(const Runnable &);
           static Runnable cast(const Object &);
           
    private:
    Runnable() {};
    public:
    ~Runnable();
    void run();
   }; // end class Runnable
  } // end namespace lang
 } // end namespace java


