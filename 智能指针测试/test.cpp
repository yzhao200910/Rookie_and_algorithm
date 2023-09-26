#include <iostream>
#include <vector>
#include <memory>
#include <string>

class temp {
public:
    temp() {
        std::cout << "object created**" <<ss<< std::endl;
        std::cout << "object created" << std::endl;
    }


    ~temp() {
        printf("%s", "object end**\n");

        printf("%s", "the sss is over\n");
    }

    void show() {
        std::cout << " i am temp" << std::endl;
    }
    void show_print(){
        std::cout<<"ss:"<<ss<<std::endl;

    }
public:
   std::string ss;

};
//std::unique_ptr<int> re_smart(){
//    std::unique_ptr<int> _ptr=std::make_unique<int>(10);
//    return _ptr;
//}
void print(std::unique_ptr<temp> temp){
    temp->ss="damn ,m3 wtf";
    std::cout << "change the sss 's value" <<temp->ss<<std::endl;
    std::cout<<temp.get()<<std::endl;

}
void ssss(temp &&temp){
    std::cout << "change the sss 's value" <<std::endl;
}


int main() {
   temp temp2;
   std::unique_ptr<temp> _ptr=std::make_unique<temp>();
    std::unique_ptr<int> ptr=std::make_unique<int>();

//    {
//        i=new(200);
//        delete i;
//
//    }
  //  _ptr->show();
   //std::cout<<_ptr.get()<<std::endl;
  //print(_ptr) ;
  std::shared_ptr<temp> tem3=std::shared_ptr<temp>();
  tem3=std::move(_ptr);
   _ptr->show();
   tem3->show();
    std::cout << "---------" << std::endl;
    return 0;

}