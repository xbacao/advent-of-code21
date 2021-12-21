

use std::fs::File;
use std::io::{self, BufRead};
use std::path::Path;

fn main() {

	if let Ok(mut lines) = read_lines("input") {

		let first = match lines.next() {
			Some(p) => match p {
				Ok(a) => a,
				Err(_a) => std::process::exit(1),
			},
			None => std::process::exit(1),
		};

		let esize: usize = first.chars().count();

		println!("esize:{:?}", esize);

		let mut count_1: Vec<i16> = vec![0; esize];
		let mut total: Vec<i16> = vec![0; esize];
		let mut most_common: Vec<bool> = vec![false; esize];


		for line in lines {
			
			if let Ok(ip) = line {
      	
      	let mut i: usize = 0;
      	
      	for c in ip.chars() {
      	
      		if c == '1' {
      			count_1[i]+=1;
      		}	else if c != '0' {
      			continue;
      		}
      		total[i] += 1;
      		i +=1;
      	}
      }
		}

		for i in 0..esize {
			if count_1[i]>total[i]/2{
				most_common[i]=true;
			} else {
				most_common[i]=false;
			}
		}

		let mut gamma: i32 = 0;
		let mut epsilon: i32 = 0;

		for i in 0..esize {
			gamma |= (most_common[i] as i32) <<esize-1-i;
			epsilon |= (!(most_common[i]) as i32)  << esize-1-i;
		}

		println!("{}", gamma*epsilon);

	}

}

fn read_lines<P>(filename: P) -> io::Result<io::Lines<io::BufReader<File>>>
where P: AsRef<Path>, {
    let file = File::open(filename)?;
    Ok(io::BufReader::new(file).lines())
}
