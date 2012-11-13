#include "slist.h"
#include "test_utils.h"
#include "slist_test_element.h"


void steel_slist_test_basic_init(){
  steel_slist_t my_list;
  steel_slist_init(&my_list, sizeof(steel_slist_test_element_t), offsetof(steel_slist_test_element_t, link));

  ASSERT_TRUE(my_list.ssl_elem_size == sizeof(steel_slist_test_element_t), "Element sizes don't match.");
  ASSERT_TRUE(my_list.ssl_link_offset == offsetof(steel_slist_test_element_t, link), "Offsets don't match.");
  ASSERT_TRUE(my_list.ssl_head == NULL, "Head isn't null.");
  ASSERT_TRUE(my_list.ssl_tail == NULL, "Tail isn't null.");
}


int main(int argc, char *argv[]){
  steel_slist_test_basic_init();
  return 0;
}

