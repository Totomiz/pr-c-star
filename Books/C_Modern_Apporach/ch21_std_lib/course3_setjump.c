//
// Created by Administrator on 2023/5/27.
//

#include <setjmp.h>

void callee(jmp_buf env) {
  longjmp(env, 1);
  /* unreachable */
}

void caller() {
  jmp_buf env;

  switch (setjmp(env)) {
	case 0:
	  callee(env);
	  /* unreachable */
	  break;
	case 1:
	  printf("returned from callee\n");
	  break;
	default:
	  printf("unexpected setjump value\n");
  }
}
