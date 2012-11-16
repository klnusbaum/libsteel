/**
 * Copyright 2012 Dave Majnemer and Kurtis Nusbaum
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef STEEL_DLIST_H
#define STEEL_DLIST_H

#include <stddef.h>

/**
 * \brief Represents a node in a singly linked list.
 */
struct steel_dlist_node {
  struct steel_dlist_node *sdn_next;
  struct steel_dlist_node *sdn_previous;
};

/**
 * \brief Convenience typedef.
 */
typedef struct steel_dlist_node steel_dlist_node_t;

/**
 * \brief Represents a node in a singly linked list.
 */
struct steel_dlist {
  size_t sdl_elem_size;
  size_t sdl_link_offset;

  steel_dlist_node_t *sdl_head;
  steel_dlist_node_t *sdl_tail;
};

/**
 * \brief Convenience typedef.
 */
typedef struct steel_dlist steel_dlist_t;

/**
 * \brief Initializes a Doubly Linked List.
 *
 * \param sdl The Doubly Linked List to be initialized.
 * \param elem_size The size of the elements comprising the Doubly Linked List.
 * \param link_offset The offset of the steel_dlist_node within each element in the Doubly Linked List.
 */
void steel_dlist_init(steel_dlist_t *sdl, size_t elem_size, size_t link_offset);

/**
 * \brief Finalizes a Doubly Linked List.
 *
 * Performs any necessary clean up for a Doubly Linked List.
 *
 * \param sdl The Doubly Linked List to finalize.
 */
void steel_dlist_fini(steel_dlist_t *sdl);

/**
 * \brief Returns the head element of a Doubly Linked List.
 *
 * \param sdl The Doubly Linked List whose head is desired.
 * \return The head element of the given Doubly Linked List. Returns NULL if the list is empty.
 */
void *steel_dlist_head(steel_dlist_t *ssl);

/**
 * \brief Returns the tail element of a Doubly Linked List.
 *
 * \param sdl The Doubly Linked List whose tail is desired.
 * \return The tail element of the given Doubly Linked List. Returns NULL if the list is empty.
 */
void *steel_dlist_tail(steel_slist_t *sdl);

/**
 * \brief Returns the element right before the given element in the Doubly Linked List.
 *
 * \param sdl The Doubly Linked List in which both elements are contained.
 * \param elem The element after the element which is desired.
 * \return The element before the given element. If the element is at the head of the list,
 * this function returns NULL.
 */
void *steel_dlist_previous(steel_dlist_t *sdl, void *elem);

/**
 * \brief Returns the element right after the given element in the Doubly Linked List.
 *
 * \param sdl The Doubly Linked List in which both elements are contained.
 * \param elem The element before the element which is desired.
 * \return The element after the given element. If the element is at the tail of the list,
 * this function returns NULL.
 */
void *steel_dlist_next(steel_dlist_t *sdl, void *elem);

/**
 * \brief Inserts a new element into the Doubly Linked List at the head of the list.
 *
 * \param ssl The Doubly Linked List into which the given element should be inserted.
 * \param elem The element to be inserted into the given Doubly Linked List.
 * \return The element that was inserted.
 */
void *steel_dlist_insert_head(steel_dlist_t *sdl, void *elem);

/**
 * \brief Inserts a new element into the Doubly Linked List at the tail of the list.
 *
 * \param sdl The Doubly Linked List into which the given element should be inserted.
 * \param elem The element to be inserted into the given Doubly Linked List.
 * \return The element that was inserted.
 */
void *steel_dlist_insert_tail(steel_dlist_t *sdl, void *elem);

/**
 * \brief Inserts a new element into the Doubly Linked List before the specified element.
 *
 * \param sdl The Doubly Linked List into which the given element should be inserted.
 * \param after The element on which given element should be inserted before in the Doubly Linked List.
 * \param elem The element to be inserted into the given Doubly Linked List.
 * \return The element that was inserted.
 */
void *steel_dlist_insert_before(steel_dlist_t *sdl, void *before, void *elem);

/**
 * \brief Inserts a new element into the Doubly Linked List after the specified element.
 *
 * \param sdl The Doubly Linked List into which the given element should be inserted.
 * \param after The element after which given element should be inserted in the Doubly Linked List.
 * \param elem The element to be inserted into the given Doubly Linked List.
 * \return The element that was inserted.
 */
void *steel_dlist_insert_after(steel_dlist_t *sdl, void *after, void *elem);

/**
 * \brief Removes the head element from the given Doubly Linked List.
 *
 * \param ssl The Doubly Linked List from which the head should be removed.
 * \return The head element that was removed from the Doubly Linked List. Returns NULL if the
 * Doubly Linked List is empty.
 */
void *steel_dlist_remove_head(steel_dlist_t *sdl);

/**
 * \brief Removes the tail from the given Doubly Linked List.
 *
 * \param ssl The Doubly Linked List from which the tail should be removed.
 * \return The head element that was removed from the Doubly Linked List. Returns NULL if the
 * Doubly Linked List is empty.
 */
void *steel_dlist_remove_tail(steel_dlist_t *ssl);

/**
 * \brief Removes the given element from the given Doubly Linked List.
 *
 * \param sdl The Doubly Linked List from which the given element should be remove.
 * \param elem The element to remove.
 * \return The element that was removed from the Doubly Linked List. Returns NULL
 * if the element is not in the Doubly Linked List.
 */
void *steel_dlist_remove(steel_dlist_t *sdl, void *elem);


#endif //STEEL_SLIST_H
