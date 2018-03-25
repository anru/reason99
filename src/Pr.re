let rec last_element_01 = (ll: list('a)) =>
  switch ll {
  | [] => None
  | [x] => Some(x)
  | [_, ...rest] => last_element_01(rest)
  };

let rec last_two_02 = (ll: list('a)) =>
  switch ll {
  | [] => None
  | [a, b] => Some((a, b))
  | [_] => None
  | [_, ...rest] => last_two_02(rest)
  };

let rec at_03 = (k: int, ll: list('a)) =>
  switch (k, ll) {
  | (0, [a, ...rest]) => Some(a)
  | (k, [_, ...rest]) => at_03(k - 1, rest)
  | (_, _) => None
  };