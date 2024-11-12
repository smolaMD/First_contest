#include <iostream>
#include "cstring.h"

size_t Strlen(const char *str) {
  size_t len = 0;
  while (str[len] != '\0') {
    ++len;
  }
  return len;
}

int Strcmp(const char *first, const char *second) {
  size_t i = 0;
  while (first[i] == second[i]) {
    if (first[i] == '\0') {
      return 0;
    }
    ++i;
  }
  if (first[i] > second[i]) {
    return 1;
  }
  return -1;
}

int Strncmp(const char *first, const char *second, size_t count) {
  if (count == 0 || (first[0] == '\0' && second[0] == '\0')) {
    return 0;
  }
  size_t i = 0;
  while (first[i] == second[i] && i < count) {
    if (first[i] == '\0') {
      return 0;
    }
    ++i;
  }
  if (i < count) {
    if (first[i] > second[i]) {
      return 1;
    }
    return -1;
  }
  return 0;
}

char *Strcpy(char *dest, const char *src) {
  size_t i = 0;
  while (src[i] != '\0') {
    dest[i] = src[i];
    ++i;
  }
  dest[i] = '\0';
  return dest;
}

char *Strncpy(char *dest, const char *src, size_t count) {
  size_t src_len = Strlen(src);
  for (size_t i = 0; i < count; ++i) {
    if (i < src_len) {
      dest[i] = src[i];
    } else {
      dest[i] = '\0';
    }
  }
  return dest;
}

char *Strcat(char *dest, const char *src) {
  size_t dest_len = Strlen(dest);
  for (int i = 0; src[i] != '\0'; ++i) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + Strlen(src)] = '\0';
  return dest;
}

char *Strncat(char *dest, const char *src, size_t count) {
  if (Strlen(src) < count) {
    return Strcat(dest, src);
  }
  size_t dest_len = Strlen(dest);
  for (size_t i = 0; i < count; ++i) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + count] = '\0';
  return dest;
}

const char *Strchr(const char *str, char symbol) {
  int i = 0;
  while (str[i] != '\0' && str[i] != symbol) {
    ++i;
  }
  if (str[i] == symbol) {
    return str + i;
  }
  return nullptr;
}

const char *Strrchr(const char *str, char symbol) {
  int i = 0;
  while (str[i] != '\0') {
    ++i;
  }
  while ((str[i] != symbol) && (i != 0)) {
    --i;
  }
  if (str[i] == symbol) {
    return str + i;
  }
  return nullptr;
}

size_t Strspn(const char *dest, const char *src) {
  size_t cnt = 0;
  while (Strchr(src, dest[cnt]) && dest[cnt] != '\0') {
    ++cnt;
  }
  return cnt;
}

size_t Strcspn(const char *dest, const char *src) {
  size_t cnt = 0;
  while (!Strchr(src, dest[cnt]) && dest[cnt] != '\0') {
    ++cnt;
  }
  return cnt;
}

const char *Strpbrk(const char *dest, const char *breakset) {
  for (int i = 0; dest[i] != '\0'; ++i) {
    if (Strchr(breakset, dest[i])) {
      return dest + i;
    }
  }
  return nullptr;
}

const char *Strstr(const char *str, const char *pattern) {
  size_t str_len = Strlen(str);
  size_t pattern_len = Strlen(pattern);
  if (pattern_len > str_len) {
    return nullptr;
  }
  for (size_t i = 0; i <= str_len - pattern_len; ++i) {
    size_t j = 0;
    for (j = 0; j < pattern_len; ++j) {
      if (str[i + j] != pattern[j]) {
        break;
      }
    }
    if (j == pattern_len) {
      return str + i;
    }
  }
  return nullptr;
}
