
import React from "react"
import css from './terminal.css'  // eslint-disable-next-line

const  Terminal = (props) => {
    return( 
        <div class="terminal-window">
        <header>
            <div class="button green"></div>
            <div class="button yellow"></div>
            <div class="button red"></div>
        </header>
        <section class="terminal">
            <div className="flex">
            <textarea 
                rows="39" 
                cols="91" 
                class="text" 
                value = {props.value}
                onChange={(event) => {props.setValue(event.target.value)}}
            />
            <textarea 
                rows="39" 
                cols="91" 
                class="text" 
                value = {props.result}
                onChange={(event) => {props.setResult(event.target.value)}}
            />
            </div>
        </section>
        </div>
    )
}
export default Terminal;
