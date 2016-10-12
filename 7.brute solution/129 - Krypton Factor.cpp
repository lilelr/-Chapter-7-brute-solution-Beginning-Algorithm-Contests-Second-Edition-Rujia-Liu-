//#include <algorithm>
//#include <cmath>
//#include <cstdio>
//#include <cstdlib>
//#include <cstring>
//#include <iostream>
//#include <map>
//#include <queue>
//#include <set>
//#include <string>
//#include <vector>
//using namespace std;
//#define LL long long
//const int maxn = 85;
//
//int n, L;
//int total;
//string str;
//string ans;
//
//bool is_repeat_next(string str) {
//  int len = str.length();
//  //  cout << "len;" << len << endl;
//  for (int i = 0; i < len; i++) {
//    char cur_char = str[i];
//    int next_index = str.find(cur_char, i + 1);
//    while (next_index != string::npos) {
//      if (next_index != string::npos) {
//        int j = i + 1, k = next_index + 1;
//        if (len - k >= next_index - j) {
//          int ok = 1;
//          for (; j < next_index, k < len; j++, k++) {
//            if (str[j] != str[k]) {
//              ok = 0;
//              break;
//            }
//          }
//          if (ok == 1) {
//            return true;
//          }
//        }
//      }
//      next_index = str.find(cur_char, next_index + 1);
//    }
//  }
//  return false;
//}
//
//// void find_hard(int cur, string str) {
////  if (cur != 0) {
////    total++;
////    cout << "str" << total << ":  " << str << endl;
////
////    if (total == n) {
////      ans = str;
////    }
////  } else {
////    for (int i = 0; i < L; i++) {
////      char add_letter = 'A' + i;
////      str += add_letter;
////      if (!is_repeat_next(str)) {
////        find_hard(cur + 1, str);
////      } else {
////        str.erase(str.length() - 1, 1);
////      }
////    }
////  }
////}
//
////
//// void find_hard(int cur, string str) {
////  total++;
////  if (total == n) {
////    ans = str;
////    return;
////  } else if (total > n) {
////    return;
////  } else {
////    for (int i = 0; i < L; i++) {
////      char add_letter = 'A' + i;
////      str += add_letter;
////      if (relation_str(str)) {
////        find_hard(cur + 1, str);
////      } else {
////        str.erase(str.length() - 1, 1);
////      }
////    }
////  }
////}
//
//int cnt;
//int s_int[100];
//int dfs(int cur) {
//  if (cnt++ == n) {
//    for (int i = 0; i < cur; i++) {
//      if (i % 64 == 0 && i > 0) {
//        cout << endl;
//      } else if (i % 4 == 0 && i > 0) {
//        cout << " ";
//      }
//      printf("%c", 'A' + s_int[i]);
//    }
//    printf("\n%d\n", cur);
//    return 0;
//  }
//
//  for (int i = 0; i < L; i++) {
//    s_int[cur] = i;
//
//    //只需判断当前串的后缀是否可能重复，如“EABCABC"
//    //存在重复，自然不会出现”EABCABCF"的下一步的子串
//    int ok = 1;
//    for (int j = 1; j * 2 <= cur + 1; j++) { // 尝试长度为j*2的后缀
//      int equal = 1;
//
//      for (int k = 0; k < j; k++) // 检查后一半是否等于前一半
//        if (s_int[cur - k] != s_int[cur - k - j]) {
//          equal = 0;
//          break;
//        }
//
//      if (equal) {
//        ok = 0;
//        break;
//      } // 后一半等于前一半，方案不合法
//    }
//    if (ok)
//      if (!dfs(cur + 1))
//        return 0;
//  }
//  return 1;
//}
//
//int my_dfs(int cur) {
//  if (cnt++ == n) {
//    for (int i = 0; i < cur; i++) {
//      if (i % 64 == 0 && i > 0) {
//        printf("\n");
//      } else if (i % 4 == 0 && i > 0) {
//        printf(" ");
//      }
//      printf("%c", 'A' + s_int[i]);
//    }
//    printf("\n%d\n", cur);
//    return 0;
//  } else {
//    for (int i = 0; i < L; i++) {
//      s_int[cur] = i;
//
//      int ok = 1;
//      for (int j = 1; j * 2 < cur + 1; j++) {
//        int equal = 1;
//        for (int k = 0; k < j; k++) {
//          if (s_int[cur - k] != s_int[cur - k - j]) {
//            equal = 0;
//            break;
//          }
//        }
//        if (equal) {
//          ok = 0;
//          break;
//        }
//      }
//      if (ok) {
//        if (!dfs(cur + 1)) {
//          return 0;
//        }
//      }
//    }
//  }
//  return 1;
//}
//
//// void solve() {
////  n++;
////  total = 0;
////  ans = "";
////  str = "";
////  find_hard(-1, str);
////
////  int ans_len = ans.length();
////  while (!ans.empty()) {
////    for (int i = 0; i < 16; i++) {
////      if (i == 0) {
////        cout << ans.substr(0, 4);
////        ans.erase(0, 4);
////      } else {
////        cout << " " << ans.substr(0, 4);
////        ans.erase(0, 4);
////      }
////    }
////    cout << endl;
////  }
////  cout << ans_len << endl;
////}
//
//int main() {
//    freopen("/Users/yuxiao/XcodeProject/7.brute solution/7.brute solution/in",
//            "r", stdin);
//    freopen("/Users/yuxiao/XcodeProject/7.brute solution/7.brute solution/out",
//            "w", stdout);
//
//  while (cin >> n >> L && (n != 0 && L != 0)) {
//    cnt = 0;
//    my_dfs(0);
//    //    cout << relation_str("EABCABCF") << endl;
//    //    cout << is_repeat_next("CABCAB") << endl;
//    //    cout << is_repeat_next("CABB") << endl;
//    //    cout << is_repeat_next("CAB") << endl;
//    //    solve();
//  }
//  return 0;
//}
