#include "slist.h"
#include "test_utils.h"
#include "slist_test_element.h"


void steel_slist_tail_insert_test(){
  steel_slist_test_element_t my_element2;
  steel_slist_test_element_t my_element1;
  steel_slist_t my_list;

  steel_slist_init(&my_list, sizeof(steel_slist_test_element_t), offsetof(steel_slist_test_element_t, link));
  my_element1.value = 5;
  my_element2.value = 1;
  steel_slist_insert_tail(&my_list, &my_element1);
  steel_slist_insert_tail(&my_list, &my_element2);
  ASSERT_TRUE(steel_slist_tail(&my_list) == &my_element2, "Head doesn't equal the second element.")
}


int main(int argc, char *argv[]){
  steel_slist_tail_insert_test();
  return 0;
}

