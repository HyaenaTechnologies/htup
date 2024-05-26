const std = @import("std");
const writer = std.io.getStdOut().writer();

pub fn main() void {
    writer.print("Local Workflow\n", .{}) catch return;
}