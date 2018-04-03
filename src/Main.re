let rec last_element = (ll: list('a)) =>
  switch ll {
  | [] => None
  | [x] => Some(x)
  | [_, ...rest] => last_element(rest)
  };

let rec last_two = (ll: list('a)) =>
  switch ll {
  | [a, b] => Some((a, b))
  | [_, ...rest] => last_two(rest)
  | _ => None
  };

let rec at = (k: int, ll: list('a)) =>
  switch (k, ll) {
  | (0, [a, ..._]) => Some(a)
  | (k, [_, ...rest]) => at(k - 1, rest)
  | (_, _) => None
  };

let rec length = (ll: list('a)) =>
  switch ll {
  | [] => 0
  | [_, ...rest] => length(rest) + 1
  };

let reverse = (ll: list('a)) => {
  let rec reversify = (acc: list('a), result: list('a)) =>
    switch (acc, result) {
    | ([a, ...rest], result) => reversify(rest, [a, ...result])
    | ([], result) => result
    };
  reversify(ll, [])
};

let is_palindrome = (ll: list('a)) => reverse(ll) == ll;

type node('a) =
  | One('a)
  | Many(list(node('a)));

let concat = (a: list('a), b: list('a)) => {
  let rec aux = (a: list('a), b: list('a)) =>
    switch (a, b) {
    | ([x], b) => [x, ...b]
    | ([x, ...rest], b) => aux(rest, [x, ...b])
    | ([], b) => b
    };
  aux(reverse(a), b)
};

let flatten = (ll: list(node('a))) => {
  let rec aux = (ll: list(node('a)), acc: list('a)) =>
    switch (ll, acc) {
    | ([One(a), ...rest], acc) => aux(rest, [a, ...acc])
    | ([Many(sublist), ...rest], acc) => aux(concat(sublist, rest), acc)
    | ([], acc) => acc
    };
  reverse(aux(ll, []))
};

let flatten2 = (ll: list(node('a))) => {
  let rec aux = (ll: list(node('a)), acc: list('a)) =>
    switch (ll, acc) {
    | ([One(a), ...rest], acc) => aux(rest, [a, ...acc])
    | ([Many(sublist), ...rest], acc) => aux(rest, aux(sublist, acc))
    | ([], acc) => acc
    };
  reverse(aux(ll, []))
};

let compress = (ll: list('a)) => {
  let rec aux = (ll: list('a), acc: list('a)) =>
    switch (ll, acc) {
    | ([x, ...rest], []) => aux(rest, [x])
    | ([x, ...rest], [y, ...res]) when x == y => aux(rest, [x, ...res])
    | ([x, ...rest], acc) => aux(rest, [x, ...acc])
    | ([], acc) => acc
    };
  reverse(aux(ll, []))
};

let rec compress2 = (ll: list('a)) =>
  switch ll {
  | [a, ...[b, ..._] as t] => a == b ? compress2(t) : [a, ...compress2(t)]
  | smaller => smaller
  };

let pack = (ll: list('a)) => {
  let rec aux = (ll: list('a), acc: list(list('a))) =>
    switch (ll, acc) {
    | ([x, ...rest], [[y, ..._] as f, ...t]) when x == y => aux(rest, [[x, ...f], ...t])
    | ([x, ...rest], acc) => aux(rest, [[x], ...acc])
    | ([], acc) => acc
    };
  reverse(aux(ll, []))
};

let encode_with_pack_rl = (ll: list('a)) : list((int, 'a)) => {
  let packed_ll = pack(ll);
  let rec aux = (l: list(list('a))) =>
    switch l {
    | [[x, ..._] as t, ...rest] => [(length(t), x), ...aux(rest)]
    | _ => []
    };

  aux(packed_ll)
};

/* # encode_rl ["a";"a";"a";"a";"b";"c";"c";"a";"a";"d";"e";"e";"e";"e"];;
- : (int * string) list =
[(4, "a"); (1, "b"); (2, "c"); (2, "a"); (1, "d"); (4, "e")] */
let encode_rl = (ll: list('a)) : list((int, 'a)) => {
  let rec aux = (l: list('a), count: int) =>
    switch l {
    | [a, ...[b, ..._] as t] => a == b ? aux(t, count + 1) : [(count, a), ...aux(t, 1)]
    | [a] => [(count, a)]
    | _ => []
    };
  aux(ll, 1)
};

module Encode = {
  type rle('a) =
    | One('a)
    | Many(int, 'a);
  
  /* encode_rle ["a";"a";"a";"a";"b";"c";"c";"a";"a";"d";"e";"e";"e";"e"];;
  - : string rle list =
  [Many (4, "a"); One "b"; Many (2, "c"); Many (2, "a"); One "d";
   Many (4, "e")] */
  let encode_rle = (ll: list('a)) : list(rle('a)) => {
    let mk = (count: int, v: 'a) => {
      count == 1 ? One(v) : Many(count, v)
    };
  
    let rec aux = (l: list('a), count: int) =>
      switch l {
      | [a, ...[b, ..._] as t] => a == b ? aux(t, count + 1) : [mk(count, a), ...aux(t, 1)]
      | [a] => [mk(count, a)]
      | _ => []
      };
    aux(ll, 1)
  }; 
}

