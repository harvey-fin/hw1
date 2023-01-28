#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_back(const std::string& val){
  size_++;
  if (tail_ == NULL || tail_->last == ARRSIZE){
    Item* n_item = new Item;
    if (tail_ == NULL){
      head_ = n_item;
      tail_ = n_item;
    }
    else{
      tail_->next=n_item;
      n_item->prev=tail_;
    }
    
    tail_ = n_item;
    n_item->val[0]=val;
    n_item->first=0;
    n_item->last=1;
  }
  else{
    tail_->val[tail_->last++]=val;
  }
}

void ULListStr::push_front(const std::string& val){
  size_++;
  if (head_ == NULL || head_->first == 0){
    Item* n_item = new Item;
    if (head_ == NULL){
      head_ = n_item;
      tail_ = n_item;
    }
    else{
      head_->prev=n_item;
      n_item->next=head_;
    }
    
    head_ = n_item;
    n_item->val[ARRSIZE-1]=val;
    n_item->first=ARRSIZE-1;
    n_item->last=ARRSIZE;
  }
  else{
    head_->val[--head_->first]=val;
  }
}

void ULListStr::pop_back(){
  if (tail_==NULL){return;}
  if (tail_->first==tail_->last){
    if (head_ == tail_){
      delete tail_;
      head_=NULL;
      tail_=NULL;

    }
    else{
      size_--;
      Item* tmp=tail_;
      tail_ = tmp->prev;
      tail_->next=NULL;
      delete tmp;
    }
  }
  else if (tail_->first==tail_->last-1){
    if (head_ == tail_){
      size_--;
      delete tail_;
      head_=NULL;
      tail_=NULL;
    }
    else{
      size_--;
      Item* tmp=tail_;
      tail_ = tmp->prev;
      tail_->next=NULL;
      delete tmp;
    }
  }
  else{
    size_--;
    tail_->val[--tail_->last]="";
  }
}

void ULListStr::pop_front(){
  if (head_==NULL){return;}
  if (head_->first==head_->last){
    size_--;
    if (head_ == tail_){
      delete head_;
      head_=NULL;
      tail_=NULL;
    }
    else{
      size_--;
      Item* tmp=head_;
      head_ = head_->next;
      head_->prev=NULL;
      delete tmp;
    }
  }
  else if (head_->first==tail_->last-1){
    if (head_ == tail_){
      size_--;
      delete tail_;
      head_=NULL;
      tail_=NULL;
    }
    else{
      size_--;
      Item* tmp=head_;
      head_ = head_->next;
      head_->prev=NULL;
      delete tmp;
    }
  }
  else{
    size_--;
    head_->val[head_->first++]="";
  }
}

std::string const & ULListStr::back() const{
  return tail_->val[tail_->last-1];
}

std::string const & ULListStr::front() const{
  return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const{
  loc+=1;
  if (head_==NULL){return NULL;}
  else if(loc>size_){return NULL;}
  else{
    Item* tmp=head_;
    while(loc>tmp->last-tmp->first){
      if (tmp==tail_){
        return NULL;
      }
      loc-=tmp->last-tmp->first;
      tmp=tmp->next;
    }
    return tmp->val+tmp->first+loc-1;
  }
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
