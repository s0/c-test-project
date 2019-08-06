int main() {
  return(0);
}

int lock1;
int lock2;
int lock3;

int something();

void mutex_lock(int *lock) { }
void mutex_unlock(int *lock) { }

void dangerous(char *tainted_param[]) { }

void func3(char *p[]) {
  mutex_lock(&lock3);

  if (something())
    mutex_unlock(&lock3);

  mutex_lock(&lock2);
  dangerous(p); /// Use of tainted param
  mutex_unlock(&lock2);
}



void func2(char *p[]) {
  mutex_lock(&lock3);
  //...
  mutex_unlock(&lock3);
  //...
  mutex_lock(&lock2);
  dangerous(p); /// Use of tainted param
  mutex_unlock(&lock2);
}



void func1(char *tainted_param[]) {
  mutex_lock(&lock1);
  func2(tainted_param);
  func3(tainted_param);
  mutex_unlock(&lock1);
}
