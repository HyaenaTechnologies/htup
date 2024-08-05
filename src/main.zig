const standard: type = @import("std");

const writer = standard.io.getStdOut().writer();

pub fn main() void {
    writer.print("htup\n", .{}) catch return;
}