----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 02/11/2025 03:39:44 PM
-- Design Name: 
-- Module Name: Lab1B - Boolean_Function
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Lab1B is
    Port ( A, B : in STD_LOGIC;
           Cathode_7SD : out STD_LOGIC_VECTOR (7 downto 0);
           Anode_7SD : out STD_LOGIC_VECTOR (7 downto 0));
end Lab1B;

architecture Comparator of Lab1B is

signal F_E, F_L, F_G: STD_LOGIC;

begin
    F_E <=  ((NOT A) AND (NOT B)) OR (A AND B);
    F_G <= (NOT B) AND A;
    F_L <=  B AND (NOT A);
    
    process(F_E, F_L, F_G)
    
    
begin
    if F_E = '1' then
        Cathode_7SD <= "01100001";
    elsif F_L = '1' then
        Cathode_7SD <= "11100011";
    elsif F_G = '1' then
        Cathode_7SD <= "01000001";
    else
        Cathode_7SD <= "11111101";
    end if;
end process;
    Anode_7SD <= "11111110";
end Comparator;
