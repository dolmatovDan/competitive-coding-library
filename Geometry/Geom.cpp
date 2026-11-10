#include <bits/stdc++.h>
using namespace std;
#define all(a) (a).begin(), (a).end()
#define len(a) ((int)((a).size()))

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-12;
const ld PI = atan2(0, -1);

struct Line;

struct Vector;

struct Vector {
  ld x, y;
  Vector(ld _x, ld _y) : x(_x), y(_y) {}
  Vector() : x(0), y(0) {}
};

bool operator==(Vector v1, Vector v2) { return v1.x == v2.x && v1.y == v2.y; }

ld operator*(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }

Vector operator*(Vector a, ld k) { return Vector(a.x * k, a.y * k); }

ld operator%(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

Vector operator+(Vector a, Vector b) { return Vector(a.x + b.x, a.y + b.y); }

Vector operator-(Vector a, Vector b) { return Vector(a.x - b.x, a.y - b.y); }

istream &operator>>(istream &in, Vector &p) {
  in >> p.x >> p.y;
  return in;
}

ostream &operator<<(ostream &out, Vector &p) {
  out << p.x << " " << p.y;
  return out;
}

struct Line {
  ld a, b, c;
  Line(ld _a, ld _b, ld _c) : a(_a), b(_b), c(_c) {}
  ld getVal(ld x) {
    assert(b != 0);
    return -(a * x) / b;
  }
};

istream &operator>>(istream &in, Line &p) {
  in >> p.a >> p.b >> p.c;
  return in;
}

ostream &operator<<(ostream &out, Line &p) {
  out << p.a << " " << p.b << " " << p.c;
  return out;
}

Line getLineByTwoPoints(Vector a, Vector b) {
  return Line(b.y - a.y, a.x - b.x, a.y * b.x - a.x * b.y);
}

ld getDist(Vector a, Vector b) {
  return sqrtl((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

ld getAngle(Vector a, Vector b, Vector c) {
  Vector v1 = a - b;
  Vector v2 = c - b;
  return atan2(v1 % v2, v1 * v2);
}

ld getAngle(Vector a, Vector b) { return atan2(a % b, a * b); }

bool isInSegment(Vector start, Vector end, Vector Y) {
  Vector v1 = start - Y;
  Vector v2 = end - Y;
  if (v1 % v2 == 0 && v1 * v2 <= 0) {
    return true;
  }
  return false;
}

Line bisector(Vector Y, Vector X, Vector Z) {
  Vector XY = Y - X;
  Vector XZ = (Z - X) * (getDist(X, Y) / getDist(X, Z));

  Vector sum = XZ + XY;
  Vector p = sum + X;
  Line res = getLineByTwoPoints(X, p);
  if (isInSegment(Y, X, Z)) {
    Line cur = getLineByTwoPoints(X, Y);
    res.a = cur.b;
    res.b = -cur.a;
    res.c = cur.a * X.y - cur.b * X.x;
  }
  return res;
}

ld getDistPointSegment(Vector start, Vector end, Vector a) {
  ld mn = -1;
  if ((start - end) * (a - end) <= 0 || (end - start) * (a - start) <= 0) {
    mn = min<ld>(getDist(start, a), getDist(end, a));
  } else {
    mn = fabs((start - a) % (end - a)) / getDist(start, end);
  }
  return mn;
}

bool isInPolygon(vector<Vector> &polygon, Vector P) {
  int n = len(polygon);
  ld sum = 0;
  bool ok = false;
  for (int i = 0; i < n; ++i) {
    Vector v1 = P - polygon[i];
    Vector v2 = P - polygon[(i + 1) % n];
    sum += getAngle(v1, v2);
    if (isInSegment(polygon[i], P, polygon[(i + 1) % n])) {
      ok = true;
    }
  }
  for (Vector p : polygon) {
    if (p.x == P.x && p.y == P.y)
      ok = true;
  }
  return fabs(sum) > PI || ok;
}

bool isInConvexPolygon(vector<Vector> &polygon, Vector P, int idxBottom) {
  int n = len(polygon);
  int idx = idxBottom;
  Vector bottom = polygon[idxBottom];
  if (bottom.y > P.y) {
    return false;
  }
  int l = 1, r = n - 1;
  while (r > l + 1) {
    int mid = (r + l) / 2;
    int midb = (mid + idx) % n; // index in array
    bool check = (P - bottom) % (polygon[midb] - bottom) >= 0;
    (check ? r : l) = mid;
  }
  vector<Vector> triangle(3);
  triangle[0] = polygon[(r + idx) % n];
  triangle[1] = polygon[(l + idx) % n];
  triangle[2] = polygon[idxBottom];
  return isInPolygon(triangle, P);
}

Vector intersectLines(Line A, Line B) {
  Vector res;
  res.y = -(A.c * B.a - B.c * A.a) / (A.b * B.a - B.b * A.a);
  res.x = -(A.c * B.b - B.c * A.b) / (A.a * B.b - B.a * A.b);
  return res;
}

ld getOrientDist(Vector start, Vector end, Vector P) {
  Vector v1 = start - P;
  Vector v2 = end - P;
  return v1 % v2 / getDist(start, end);
}

bool isCrossingSegments(Vector A, Vector B, Vector C, Vector D) {
  ld s1 = getOrientDist(A, B, C);
  ld s2 = getOrientDist(A, B, D);
  ld s3 = getOrientDist(C, D, A);
  ld s4 = getOrientDist(C, D, B);
  if (isInSegment(A, B, C) || isInSegment(A, B, D) || isInSegment(C, D, A) ||
      isInSegment(C, D, B)) {
    return true;
  }
  return s1 * s2 < 0 && s3 * s4 < 0;
}

ld getOrientArea(vector<Vector> polygon) {
  int n = len(polygon);
  ld s = 0;
  for (int i = 0; i < n; ++i) {
    Vector v1 = polygon[i];
    Vector v2 = polygon[(i + 1) % n];
    s += v1 % v2;
  }
  return s / 2;
}

bool isInAngle(Vector A, Vector O, Vector B, Vector P) {
  return ((B - O) % (P - O)) * ((B - O) % (A - O)) >= 0 &&
         ((A - O) % (P - O)) * ((A - O) % (B - O)) >= 0;
}

vector<int> buildConvexHull(vector<Vector> polygon) {
  int n = len(polygon);
  Vector left = polygon[0];
  vector<pair<Vector, int>> polygon2(n);
  for (int i = 0; i < n; ++i) {
    if (polygon[i].x < left.x) {
      left = polygon[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    polygon2[i] = {polygon[i] - left, i};
  }
  sort(all(polygon2), [&](pair<Vector, int> p1, pair<Vector, int> p2) {
    return p1.first % p2.first > 0 ||
           (p1.first % p2.first == 0 &&
            getDist(Vector(0, 0), p1.first) < getDist(Vector(0, 0), p2.first));
  });
  vector<int> res;
  vector<pair<Vector, int>> st;
  for (int i = 0; i < n; ++i) {
    while (len(st) >= 2 && (polygon2[i].first - st.back().first) %
                                   (st[len(st) - 2].first - st.back().first) <=
                               0) {
      st.pop_back();
    }
    st.push_back(polygon2[i]);
  }
  for (auto x : st) {
    res.push_back(x.second);
  }
  return res;
}

ld getPerimeter(vector<Vector> polygon) {
  ld res = 0;
  int n = len(polygon);
  for (int i = 0; i < n; ++i) {
    res += getDist(polygon[i], polygon[(i + 1) % n]);
  }
  return res;
}

template <class T> int getSign(T x) {
  if (x > 0)
    return 1;
  if (x < 0)
    return -1;
  return 0;
}

bool isInTriangle(vector<Vector> polygon, Vector P) {
  ll p1 = (polygon[0] - P) % (polygon[1] - P);
  ll p2 = (polygon[1] - P) % (polygon[2] - P);
  ll p3 = (polygon[2] - P) % (polygon[0] - P);
  return getSign(p1) * getSign(p2) >= 0 && getSign(p2) * getSign(p3) >= 0 &&
         getSign(p1) * getSign(p3) >= 0;
}

signed main() { return 0; }
