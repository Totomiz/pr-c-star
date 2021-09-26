//
// Created by solt on 2021/9/10.
//

#ifndef C_STAR_BASE64_H
#define C_STAR_BASE64_H

#endif //C_STAR_BASE64_H


int Base64decode_len(const char *bufcoded);

int Base64decode(char *bufplain, const char *bufcoded);

int Base64encode_len(int len);

int Base64encode(char *encoded, const char *string, int len);

char* base64_encode(char* plain);

char* base64_decode(char* cipher);