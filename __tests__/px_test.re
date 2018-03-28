open Jest;

open Main;

describe(
  "99 problems",
  () => {
    open Expect;
    test("p01_1", () => expect(last_element([12, 21, 47])) |> toEqual(Some(47)));
    test("p01_2", () => expect(last_element([])) |> toBe(None));
    test("p02_1", () => expect(last_two([12, 21, 47])) |> toEqual(Some((21, 47))));
    test("p02_2", () => expect(last_two(["12", "21", "47"])) |> toEqual(Some(("21", "47"))));
    test("p02_3", () => expect(last_two([12])) |> toBe(None));
    test("p03_1", () => expect(at(1, [12, 21, 47])) |> toEqual(Some(21)));
    test("p03_2", () => expect(at(2, [12, 21, 47])) |> toEqual(Some(47)));
    test("p03_2", () => expect(at(6, [12, 21, 47])) |> toEqual(None));
    test("p04_1", () => expect(length([12, 21, 47])) |> toEqual(3));
    test("p04_1", () => expect(length([])) |> toEqual(0));
    test("p05_1", () => expect(reverse([12, 21, 47])) |> toEqual([47, 21, 12]));
    test("p05_2", () => expect(reverse([])) |> toEqual([]));
    test("p06_1", () => expect(is_palindrome([1, 2, 3, 2, 1])) |> toBe(true));
    test("p06_1", () => expect(is_palindrome([1, 2, 2, 1])) |> toBe(true));
    test("p06_1", () => expect(is_palindrome([1, 2, 2, 2])) |> toBe(false));
    let nested_list = [One("a"), Many([One("b"), Many([One("c"), One("d")]), One("e")])];
    let flattened_list = ["a", "b", "c", "d", "e"];
    test("flatten", () => expect(flatten(nested_list)) |> toEqual(flattened_list));
    test("flatten2", () => expect(flatten2(nested_list)) |> toEqual(flattened_list));
    let llist = ["a", "a", "a", "a", "b", "c", "c", "a", "a", "d", "e", "e", "e", "e"];
    test("compress", () => expect(compress(llist)) |> toEqual(["a", "b", "c", "a", "d", "e"]))
  }
);