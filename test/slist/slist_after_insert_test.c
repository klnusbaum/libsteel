#include "slist.h"
#include "test_utils.h"
#include "slist_test_element.h"


void steel_slist_after_insert_test(){
  steel_slist_test_element_t my_element1;
  steel_slist_test_element_t my_element2;
  steel_slist_test_element_t my_element3;
  steel_slist_test_element_t* second_elem;
  steel_slist_t my_list;

  steel_slist_init(&my_list, sizeof(steel_slist_test_element_t), offsetof(steel_slist_test_element_t, link));
  my_element1.value = 5;
  my_element2.value = 1;
  my_element3.value = 9;
  steel_slist_insert_tail(&my_list, &my_element1);
  steel_slist_insert_tail(&my_list, &my_element2);
  steel_slist_insert_after(&my_list, &my_element1, &my_element3);
  second_elem = (steel_slist_test_element_t*)steel_slist_next(&my_list, &my_element1);


  ASSERT_TRUE(&my_element3 == second_elem, "Head doesn't equal the second element.")
}


int main(int argc, char *argv[]){
  steel_slist_after_insert_test();
  return 0;
}

