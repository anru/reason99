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
  let rec flattenify = (ll: list(node('a)), acc: list('a)) =>
    switch (ll, acc) {
    | ([One(a), ...rest], acc) => flattenify(rest, [a, ...acc])
    | ([Many(sublist), ...rest], acc) => flattenify(concat(sublist, rest), acc)
    | ([], acc) => acc
    };
  reverse(flattenify(ll, []))
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